using namespace std;

class Double_list
{
  private:
    struct Node
    {
      int data;
      Node *next;
      Node *prev;
    };
    Node *first;
    Node *last;
    int size;

  public:
    Double_list();
    ~Double_list();

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
