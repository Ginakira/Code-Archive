class Node {
   public:
    int data;
    Node *next;
    Node();
    Node(int val);
};

class LinkedList {
   private:
    Node head;
    int length;

   public:
    LinkedList();
    bool insert(int index, int val);
    bool delete_node(int index);
    int search(int val);
    bool reverse();
    int get_len();
    void output();
};