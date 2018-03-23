using namespace std;

class Single_list
{
  private:
    struct Node
    {
     int data;
     Node *next;
    };
    int size;
    Node *first;
    Node *last;

  public:
    Single_list();
    ~Single_list();

    void push(int data);
    void insert(int data, int point);
    void pop();
    void remove(int point);
    void delete_second();
    string turn_list_into_string();

    int get_first();
    int get_last();
    int get_size()
    {
      return size;
    }  
};
