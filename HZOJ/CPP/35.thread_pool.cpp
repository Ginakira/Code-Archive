/************************************************************
     File Name : 35.thread_pool.cpp
     Author: Ginakira
     Mail: ginakira@outlook.com
     Github: https://github.com/Ginakira
     Created Time: 2020/08/13 16:08:12
 ************************************************************/
#include <algorithm>
#include <cmath>
#include <condition_variable>
#include <iostream>
#include <map>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>
using namespace std;

class Task {
   public:
    template <typename T, typename... ARGS>
    Task(T func, ARGS... args) {
        this->func = std::bind(func, forward<ARGS>(args)...);
    }

    void operator()() {
        this->func();
        return;
    }

   private:
    function<void()> func;
};

class ThreadPool {
   public:
    ThreadPool(int n = 5) : max_threads_num(n) {}

    void start() {
        for (int i = 0; i < max_threads_num; ++i) {
            threads.push_back(new thread(&ThreadPool::worker, this));
        }
        return;
    }

    void worker() {
        thread::id id = this_thread::get_id();
        is_running[id] = true;
        while (is_running[id]) {
            Task *t = this->getOneTask();
            (*t)();
            delete t;
        }
        return;
    }

    void stop() {
        for (int i = 0; i < this->max_threads_num; ++i) {
            this->addOneTask(&ThreadPool::stop_task, this);
        }
        for (int i = 0; i < this->max_threads_num; ++i) {
            threads[i]->join();
            delete threads[i];
        }
        threads.clear();
        // do {
        //     unique_lock<mutex> lock(m_mutex);
        //     while (!task_queue.empty()) task_queue.pop();
        // } while (0);
        return;
    }

    template <typename T, typename... ARGS>
    void addOneTask(T func, ARGS... args) {
        unique_lock<mutex> lock(m_mutex);
        this->task_queue.push(new Task(func, forward<ARGS>(args)...));
        m_cond.notify_one();
        return;
    }

   private:
    void stop_task() {
        thread::id id = this_thread::get_id();
        is_running[id] = false;
        return;
    }
    Task *getOneTask() {
        /** @explain:
            因为我们要操作临界区资源，进入临界区，所以要先进行抢占互斥锁。
            加完锁后如果发现队列为空，则释放掉锁并等待一个条件变量的满足（notify）
            如果队列非空，则对临街资源进行相关操作。操作完成后释放互斥锁
        */
        unique_lock<mutex> lock(m_mutex);
        /**
         * @tip: 为什么使用if不使用while会出现段错误？
         * 使用if判断时，如果收到了信号但此时这个任务已经被其他线程取走
         * 则队列仍然是空的，此时继续进行操作就会发生错误
         * 所以应该使用while判断，直到队列非空
         */
        while (task_queue.empty()) {
            // 临时释放互斥锁 阻塞等待被通知(notify)
            // 得到通知后 抢占互斥锁  （食堂打饭）
            m_cond.wait(lock);
        }
        Task *t = task_queue.front();
        task_queue.pop();
        return t;
    }

    int max_threads_num;
    vector<thread *> threads;
    queue<Task *> task_queue;
    map<thread::id, bool> is_running;

    std::mutex m_mutex;
    std::condition_variable m_cond;
};

void thread_func1(int a, int b) {
    cout << a << " + " << b << " = " << a + b << endl;
    return;
}

void thread_func2(int &n) {
    n += 1;
    return;
}

void task_func(int x) {
    cout << "task : func" << endl;
    return;
}

int main() {
    Task t1(thread_func1, 3, 4);
    Task t2(thread_func1, 5, 6);
    Task t3(thread_func1, 7, 8);
    t1(), t2(), t3();

    int n = 0;
    Task t4(thread_func2, ref(n));
    t4(), t4(), t4();
    cout << n << endl;

    ThreadPool tp(6);
    tp.start();

    tp.addOneTask(task_func, 123);
    tp.addOneTask(task_func, 123);
    tp.addOneTask(task_func, 123);
    tp.addOneTask(task_func, 123);
    tp.stop();
    tp.addOneTask(task_func, 123);
    tp.addOneTask(task_func, 123);
    tp.addOneTask(task_func, 123);

    return 0;
}