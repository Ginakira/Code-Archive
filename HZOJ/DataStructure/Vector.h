class Vector {
   private:
    int size, length;
    int *data;

   public:
    Vector();
    Vector(int size_num);
    void expand();
    void insert(int index, int val);
    int search(int val);
    void delete_element(int index);
    void output();
};