#include<iostream>
#include<string>
using namespace std;
class MyList{
    public:
    struct  Link{
        int val;
        struct Link* next;
        Link(int _val):val(_val),next(nullptr){}
    };
    MyList(){
        dummy = new Link(0);
        size = 0;
    }
    void insert(int n,int val)
    {
        Link* newnode = new Link(val);
        Link* h = dummy;
        while(h->next)
        {
            if(h->next->val==n)
            {
                Link* tmp = h->next;
                h->next = newnode;
                newnode->next = tmp;
                size++;
                return;
            }
            h = h->next;
        }
        h->next = newnode;
        size++;
        return;
        
    }
    void deleteh(int vall)
    {
        Link* tmp = dummy;
        while(tmp->next)
        {
                if(tmp->next->val == vall)
               {
                  Link* p = tmp->next;
                  tmp->next = tmp->next->next;
                  free(p);
                    size--;
                    return;
               }
            tmp = tmp->next;
        }
        return;
    }
    void print(){
        Link* no = dummy;
        if(size ==0 )cout<<"NULL";
        else 
        { 
            while(no->next)
          {
            cout << no->next->val <<" ";
                no = no->next;
          }
        }
        return;
    }
   private:int size;
            Link* dummy;
};
int main()
{
    MyList k;
    int n1;
    cin >> n1;
    string s;
    while(n1--)
    {
        cin >> s;
        if(s=="insert")
        {
            int n2,val;
            cin >> n2 >> val;
            k.insert(n2, val);
        }
        else{
            int m;
            cin >> m;
            k.deleteh(m);
        }
    }
    k.print();
    return 0;
}
