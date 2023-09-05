 #include<iostream>
#include<string>
using namespace std;
//dynamic array
struct person
{
    string name;
    string phoneNumber;

    bool operator==(person& other) {
        return this->name == other.name;
    }

    friend ostream& operator<<(ostream& os, person& p)
    {
        os << "Name : " << p.name << " " << "phone Number: " << p.phoneNumber;
        return os;
    }
};


template<class T>
class Array{
    private:
    T* arr;
    int size;
    int capacity;
    public:
    Array(){
        size=0;
        capacity=10;
        arr=new T[capacity];
    }
  void add(T val){
    if(capacity==size)
    {
        capacity*=2;
        T *newArr=new T[capacity];

        for (int i = 0; i < size; i++)
        {
            newArr[i]=arr[i];
        }
        delete []arr;
        arr=newArr;
        delete []newArr;
    }
    arr[size]=val;
    size++;
  }
  void addFromPosition(int index,T val)
  {
    if(index<0||index>=size)
    {
        cout<<"error index out of range <0 || >size array"<<endl;
        return;
    }
    for(int i=size-1;i>=index;i--)
    {
     arr[i+1]=arr[i];
    }
    arr[index]=val;
    size++;
  }
  void remove_at(int index)
  {
    if (index<0||index>=size)
    {
        cout<<"index is error out of range <0 || >size array"<<endl;
        return;
    }
    for(int i=index;i<size;i++)
    {
    arr[i]=arr[i+1];
    }
    size--;
  }
  void set(int index,T val)
  {
    if(index<0||index>=size)
    {
        cout<<"index is error out of range <0 or >size"<<endl;
        return;
    }
   arr[index]=val;
  }
  //sort array
  void sort()
  {
    for(int i=0;i<size;i++)
    for(int j=i+1;j<size;j++)
    {
        if(arr[i]>=arr[j])
        {
            T temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
  }
  //search by value
  T searchByValue(T val)
  {
    int check=-100;
    T value;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==val)
        {
            value=arr[i];
            check =1;
            break;
        }
    }
    if (check!=-100)
    {
       return value;
    }
    cout<<"not found this value "<<val <<" in array"<<endl;
    return -1;

  }

  T at(int index)
  {
    if (index<0||index>size-1)
    {
        cout<<"index is error out of range index <0 || index >size"<<endl;
        return -1;
    }
    return arr[index];
  }
  bool remove(T val)
  {
    int index=-1;

    for(int i=0;i<size;i++)
    {
        if(arr[i]==val)
        {
            index=arr[i];
            break;
        }
    }
    if(index!=-1)
    {
        remove_at(index);
        //cout<<"removed successfly "<<endl;
        return true;
    }
    else
    {
        //cout<<"removed valid not found item"<<endl;
        return false;
    }
  }

  void clear()
  {
    for (int i = 0; i < size; i++)
    {
        arr[i]=NULL;
    }
      size=0;
  }
  int getsize()
  {
    return size;
  }
  int getcapacity()
  {
    return capacity;
  }
bool isempty()
{
return size=0;
}
void print()
{
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
};
//node single linked list
template <typename T>

 class Node{
    public:
    T item;
    Node<T> *next;

    Node(T data)
    {
      item=data;
      next=nullptr;
    }
};

//class stack
template<class T>
class stack{
private:
int size;
Node<T> *top;
public:
stack()
{
    top=nullptr;
    size=0;
}
bool isempty()
{
    return size==0;
}

int getsize()
{
    return size;
}
void push(T val){
    Node<T> *n=new Node(val);
if (top==nullptr)
{
    top=n;
}
else{
    n->next=top;
    top=n;
}
size++;
}
void pop()
{
if(isempty())
{
    cout<<"stack is empty "<<endl;
    return;
}
Node<T> *temp=top;
top=top->next;
temp=nullptr;
delete temp;
size--;
}
T peek()
{
    if (top==nullptr)
    {
        cout<<"stack is empty"<<endl;
        return T();
    }
    return top->item;
}
void printStack()
{
    Node<T> *curr=top;
    while (curr!=nullptr)
    {
        cout<<curr->item<<"  ";
        curr=curr->next;
        cout<<endl;
    }


}
};
//class queue
template<class T>
class Queue{
private:
Node<T>* front;
Node<T>*rear;
int size;
public:
Queue(){
front=nullptr;
rear=nullptr;
size=0;
}
int getSize(){
    return size;
}
bool isEmpty()
{
    return size==0;
}
void enqueue(T val){
    Node<T> *n=new Node(val);
 if(isEmpty())
 {
    front=n;
    rear=n;
 }
 else
 {
    rear->next=n;
    rear=n;
 }
 size++;
}
void dequeue()
{
    if(isEmpty())
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    Node<T>* temp=front;
    front=front->next;
    temp=nullptr;
    delete temp;
    size--;
}
T peek()
{
    if (isEmpty)
    {
        cout<<"queue is empty"<<endl;
        return T();
    }
    return front->item;
}
T Front()
{
    if (isEmpty())
    {
        return T();
    }
    else
    {
        return front->item;
    }

}
T Back()
{
    if(isEmpty())
    {
        return T();
    }
    else{
        return rear->item;
    }
}
void display()
{
Node<T> *curr=front;
while (curr!=nullptr)
{
    cout<<curr->item<<"  ";
    curr=curr->next;
}
cout<<endl;
}

};
//node double linked list
template<typename T>

class DNode {
public:
    T item;
    DNode<T>* prev;
    DNode<T>* next;

    DNode(T data){
        item=data;
        prev = nullptr;
        next=nullptr;
    }
};


//class single linked list
template<typename T>
class slist{
    protected:
    Node<T> *head;
    Node<T> *tail;
    int size;
    public:
    slist()
    {
        size=0;
        head=nullptr;
        tail=nullptr;
    }
    virtual void insertAtFront(T val)
    {
        Node<T> *n=new Node(val);
        if (head==nullptr)
        {
         head=n;
         tail=n;
        }
        else
        {
            n->next=head;
            head=n;
        }
        size++;
    }
     virtual void insertAtEnd(T val){
      if(head==nullptr)
      {
        insertAtFront(val);
      }
      else{
      Node<T> *n=new Node(val);
      tail->next=n;
      tail=n;
      size++;
      }
    }
    virtual void insertAtPos(int pos,T val)
    {
        if(pos<0||pos>size-1)
        {
            cout<<"the position is error"<<endl;
            return;
        }
        else if (pos==0)
        {
            insertAtFront(val);
        }
        else if (pos==size-1)
        {
            insertAtEnd(val);
        }
        else
        {
            Node<T> *temp=head;
            Node<T> *n=new Node(val);
             for (int i = 0; i < pos-1; i++)
             {
                temp=temp->next;
             }
             n->next=temp->next;
             temp->next=n;
             size++;
        }

    }
    virtual void removeAtFront()
    {
     if(head==nullptr)
     {
        cout<<"list is empty not any element for removed it"<<endl;
        return;
     }
     Node<T> *temp=head;
     head=head->next;
     temp->next=nullptr;
     delete temp;

     size--;
     if(head==nullptr)
     {
        tail=head=nullptr;
     }
    }
    virtual void removeAtEnd()
    {
        if(tail==nullptr)
        {
         cout<<"list is empty not any element for removed it"<<endl;
        return;
        }
        if (head==tail)
        {
            head=tail=nullptr;
        }
        else
        {
        Node<T> *temp=head;
        while (temp->next!=tail)
        {
            temp=temp->next;
        }
        temp->next=nullptr;
        delete tail;
        tail=temp;
        }
       size--;
    }
    virtual void removeAtPos(int pos)
    {
     if (pos<0||pos>size-1)
     {
        cout<<"possition is error"<<endl;
        return;
     }
     else if(pos==0)
     {
        removeAtFront();
     }
     else if(pos==size-1)
     {
        removeAtEnd();
     }
     else
     {
        Node<T> *curr=head;
        Node<T> *temp=nullptr;
        for(int i=0;i<pos-1;i++)
        {
            curr=curr->next;
        }
        temp=curr->next;
        curr->next=temp->next;
        temp->next=nullptr;
        delete temp;
        size--;
     }
    }
    virtual T findNode(T val)
    {
        int pos;
        Node<T>* curr=head;
        while (curr!=nullptr)
        {
            if(curr->item==val)
            {
            return curr->item;
            }
              curr=curr->next;
              pos++;
        }
     return T();
    }
    virtual void printList() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->item << " ";
            current = current->next;
        }
        cout << endl;
    }
    virtual int getposition(T val)
    {
        int pos;
        Node<T> *curr=head;
        while (curr!=nullptr)
        {
            if(curr->item==val)
            {
                return pos;
            }
            curr=curr->next;
            pos++;
        }
        return -1;
    }

   virtual T getelemnt(int pos)
    {
        if(pos==0)
        {
            return head->item;
        }
        else if(pos==size-1)
        {
            return tail->item;
        }
        else
        {
            Node<T>* temp=head;
            for(int i=0;i<pos;i++)
            {
                temp=temp->next;
            }
            return temp->item;
        }
    }
};

//class circular single list
template <typename T>
class circularSlist:protected slist<T>{
public:

void insertAtFront(T val) override {
        Node<T> *n = new Node<T>(val);
        if (this->head == nullptr) {
            this->head = n;
            this->tail = n;
            n->next = this->head;
        } else {
            n->next = this->head;
            this->head = n;
            this->tail->next = this->head;
        }
        this->size++;
    }

void insertAtEnd(T val) override{
    Node<T> *n=new Node<T>(val);
    if(this->head==nullptr)
    {
        insertAtFront(val);
    }
    else
    {
        this->tail->next=n;
        this->tail=n;
        this->tail->next=this->head;
    this->size++;
    }
}
void insertAtPos(int pos,T val)override
{
    if(pos<0||pos>=this->size)
    {
        cout<<"possition is error"<<endl;
        return;
    }
    else if(pos==0)
    {
        insertAtFront(val);
    }
    else if(pos==this->size)
    {
        insertAtEnd(val);
    }
    else
    {
        Node<T> *temp=this->head;
        Node<T> *n=new Node<T>(val);
        for(int i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
         n->next=temp->next;
         temp->next=n;
         this->size++;
    }
}
void removeAtFront() override{
    if (this->head==nullptr)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    Node<T> *temp=this->head;
    this->head=this->head->next;
    temp->next=nullptr;
    delete temp;
    this->tail->next=this->head;
    this->size--;
}
void removeAtEnd() override{
if (this->head==nullptr)
{
    cout<<"list is empty"<<endl;
    return;
}
if (this->head==this->tail)
{
   delete this->head;
    this->head=this->tail=nullptr;
}
else{
Node<T> *temp=this->head;
while (temp->next!=this->tail)
{
    temp=temp->next;
}
delete this->tail;
this->tail=temp;
this->tail->next=this->head;
}
this->size--;
}
void removeAtPos(int pos)
{
    if(pos<0||pos>=this->size)
    {
    cout<<"list is empty"<<endl;
    return;
    }
    else if(pos==0)
    {
        removeAtFront();
    }
    else if(pos==this->size-1)
    {
        removeAtEnd();
    }
    else{
    Node<T> *curr=this->head;
    Node<T> *Temp=nullptr;

    for(int i=0;i<pos-1;i++)
    {
     curr=curr->next;
    }
    Temp=curr->next;
    curr->next=Temp->next;
    Temp->next=nullptr;
    delete Temp;
    this->size--;
    }
}
void printList() override{
    if(this->head==nullptr)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    Node<T> *curr=this->head;
    do{
        cout<<curr->item<<" ";
        curr=curr->next;
    }while (curr!=this->head);
    cout<<endl;
}
};

//double linked list
template <typename T>
class dlist{
    protected:
    DNode<T> *head;
    DNode<T> *tail;
    int size;
    public:
    dlist()
    {
        head=nullptr;
        tail=nullptr;
        size=0;
    }
    virtual void insertAtFront(T val)
    {
        DNode<T> *n=new DNode(val);
        if(head==nullptr)
        {
            head=n;
            tail=n;
        }
        else{
        n->next=head;
        head->prev=n;
        head=n;
        }
        size++;
    }

    virtual void insertAtEnd(T val)
    {
        if(head==nullptr)
        {
            insertAtFront(val);
        }
        else
        {
            DNode<T> *n=new DNode(val);
            tail->next=n;
            n->prev=tail;
            tail=n;
            size++;
        }
    }


    virtual void insertAtPos(int pos, T val) {
        if (pos < 0 || pos >= size) {
            cout << "position is error" << endl;
            return;
        } else if (pos == 0) {
            insertAtFront(val);
        } else if (pos == size - 1) {
            insertAtEnd(val);
        } else {
            DNode<T> *curr = head;
            DNode<T> *n = new DNode<T>(val); // Create a new DNode for the given value

            for (int i = 0; i < pos - 1; i++) {
                curr = curr->next;
            }

            n->next = curr->next;
            n->prev = curr;
            curr->next->prev = n;
            curr->next = n;

            size++;
        }
    }

    virtual void removeAtFront()
    {
        if(head==nullptr)
        {
            cout<<"double list is empty"<<endl;
            return;
        }
        else
        {
            DNode<T> *temp=head;
            head=head->next;
            head->prev=nullptr;
            temp->next=nullptr;
            delete temp;
        }
        size--;
    }
    virtual void removeAtEnd()
    {
        if(head==nullptr)
        {
            cout<<"double list is empty"<<endl;
            return;
        }
        if(head==tail)
        {
            head=tail=nullptr;
        }
        else{
            DNode<T> *temp=tail;
            tail=tail->prev;
            tail->next=nullptr;
            temp->prev=nullptr;
            delete temp;
        }
        size--;
    }
    virtual void removeAtPos(int pos)
    {
        if(pos<0||pos>=size)
        {
            cout<<"position is error"<<endl;
            return;
        }
        if(pos==0)
        {
            removeAtFront();
        }
        else if(pos==size-1)
        {
            removeAtEnd();
        }
        else
        {
            DNode<T> *temp=nullptr;
            DNode<T> *curr=head;
            for (int i = 0; i < pos-1; i++)
            {
                curr=curr->next;
            }
            temp=curr->next;
            curr->next=temp->next;
            temp->next->prev=curr;
            temp=nullptr;
            delete temp;
            size--;
        }
    }
   virtual void printList()
    {
    DNode<T> *curr=head;
    while (curr!=nullptr)
    {
        cout<<curr->item<<" ";
        curr=curr->next;
    }
    cout<<endl;
    }
};

template<typename T>

class cdlist:protected dlist<T>{
public:
void insertAtFront(T val) override{
    DNode<T> *n=new DNode(val);
    if (this->head==nullptr)
    {
        this->head=n;
        this->tail=n;
        n->next=this->head;
    }
    else{
        n->next=this->head;
        this->head->prev=n;
        this->head=this->head->prev;
        this->tail->next=this->head;
        this->head->prev=this->tail;
    }
    this->size++;
}

void insertAtEnd(T val) override{

if(this->head==nullptr)
{
    insertAtFront(val);
}
else
{
DNode<T> *n=new DNode(val);
this->tail->next=n;
n->prev=this->tail;
this->tail=n;
this->tail->next=this->head;
this->head->prev=this->tail;
this->size++;
}

}
void insertAtPos(int pos,T val) override{
    if(pos<0||pos>=this->size)
    {
        cout<<"position is error"<<endl;
        return;
    }
    if (pos==0)
    {
        insertAtFront(val);
    }
    else if (pos==this->size-1)
    {
        insertAtEnd(val);
    }
    else{
        DNode<T> *curr=this->head;
        for(int i=0;i<pos-1;i++)
        {
            curr=curr->next;
        }
        DNode<T> *n=new DNode(val);
    n->next=curr->next;
    curr->next->prev=n;
    curr->next=n;
    n->prev=curr;
    this->size++;
    }

}

void removeAtFront() override
{
    if(this->head==nullptr)
    {
        cout<<"error list is empty"<<endl;
        return;
    }
    else if(this->head==this->tail)
    {
        this->head=this->tail=nullptr;
    }
    else
    {
        DNode<T> *temp=this->head;
        this->head=this->head->next;
        temp=nullptr;
        this->tail->next=this->head;
        this->head->prev=this->tail;
        delete temp;
    }
    this->size--;

}
void removeAtEnd() override{
    if(this->head==nullptr)
    {
        cout<<"error list is empty"<<endl;
        return;
    }
    else if(this->head==this->tail)
    {
        this->head=this->tail=nullptr;
    }
    else{
        DNode<T> *temp=this->tail;
        this->tail=this->tail->prev;
        temp=nullptr;
        this->tail->next=this->head;
        this->head->prev=this->tail;
        delete temp;
    }
    this->size--;
}
void removeAtPos(int pos) override{
    if (pos<0||pos>=this->size)
    {
        cout<<"the position is error"<<endl;
        return;
    }
    if(pos==0)
    {
        removeAtFront();
    }
    else if(pos==this->size-1)
    {
        removeAtEnd();
    }
    else
    {
        DNode<T> *curr=this->head;

        for (int i = 0; i < pos-1; i++)
        {
            curr=curr->next;
        }
        DNode<T> *temp=curr->next;
        temp->next->prev=curr;
        curr->next=temp->next;
        temp=nullptr;
        delete temp;
        this->size--;
    }

}
void printList()
{
    //first method
    DNode<T> *curr=this->head;
   /* do
    {
        cout<<curr->item<<" ";
        curr=curr->next;
    } while (curr!=this->head);
    cout<<endl;*/

    //second method

   /* cout<<curr->item<<" ";
    curr=curr->next;
    while (curr!=this->head){
        cout<<curr->item<<" ";
        curr=curr->next;
    }
    cout<<endl;*/
    //third method
    while (curr!=nullptr)
    {
        cout<<curr->item<<" ";
        curr=curr->next;
        if (curr==this->head)
        {
          break;
        }

    }


}
};


class integreatedProject {
    slist<person>* namesAndNumbers;
    stack<person>* callRecords;
    Queue<string>* requestQueue;
    person groupFamily[20];
    person groupWork[20];
    person groupFreind[20];

    int sizeFamily;
    int sizeWork;
    int sizeFriend;
public:
    integreatedProject() : namesAndNumbers(new slist<person>), callRecords(new stack<person>), requestQueue(new Queue<string>) {
        sizeFamily=0;
        sizeWork=0;
        sizeFriend=0;
    }
     void addRecord(string name, string number) {
        person newPerson;
        newPerson.name = name;
        newPerson.phoneNumber = number;
        namesAndNumbers->insertAtEnd(newPerson);
        cout << "Added successfully" << endl;
    }

     void addToGroup(int groupIndex, string name, string phoneNumber) {
    if (groupIndex < 1 || groupIndex > 3) {
        cout << "index is error out of range" << endl;
        return;
    }

    person newPerson;
    newPerson.name = name;
    newPerson.phoneNumber = phoneNumber;
    person p;
    p=namesAndNumbers->findNode(newPerson);
    if (p.name==name)
    {
        cout<<"record is found"<<endl;
    }
    else
    {
        addRecord(p.name,p.phoneNumber);
    }

    if (groupIndex == 1) {
        if (sizeFamily == 20) {
            cout << "group is full" << endl;
            return;
        }
        groupFamily[sizeFamily++] = newPerson;
    }
    else if (groupIndex == 2) {
        if (sizeWork == 20) {
            cout << "group is full" << endl;
            return;
        }
        groupWork[sizeWork++] = newPerson;
    } else if (groupIndex == 3) {
        if (sizeFriend == 20) {
            cout << "group is full" << endl;
            return;
        }
        groupFreind[sizeFriend++] = newPerson;
    }
}

      void printGroubLog(int groubNum){

        if (groubNum<1||groubNum>3)
        {
            cout<<"index out of range "<<endl;
            return;
        }

           if(groubNum==1)
           {
            cout<<"=============================================================================="<<endl;
            cout<<"============================ group family Log ================================"<<endl;
            cout<<"=============================================================================="<<endl;
            for (int i = 0; i < sizeFamily; i++)
            {
                cout<<"Name : "<<groupFamily[i].name<<endl;
                cout<<"Phone Number : "<<groupFamily[i].phoneNumber<<endl;
            }

           }

          else if(groubNum==2)
           {
            cout<<"=============================================================================="<<endl;
            cout<<"============================ group work Log ================================"<<endl;
            cout<<"=============================================================================="<<endl;
            for (int i = 0; i < sizeWork; i++)
            {
                  cout<<"Name : "<<groupWork[i].name<<endl;
                cout<<"Phone Number : "<<groupWork[i].phoneNumber<<endl;
            }

           }
          else if(groubNum==3)
           {
            cout<<"=============================================================================="<<endl;
            cout<<"============================ group freind Log ================================"<<endl;
            cout<<"=============================================================================="<<endl;
            for (int i = 0; i < sizeFriend; i++)
            {
                  cout<<"Name : "<<groupFreind[i].name<<endl;
                cout<<"Phone Number : "<<groupFreind[i].phoneNumber<<endl;
            }

           }
           cout<<"========================================== END ==================================="<<endl;
        }




        int searchItemFromGroup(int numGroup,string n)
        {
            int IndexItem;
          if(numGroup<0||numGroup>2)
          {
            cout<<"index out of range"<<endl;
            return -1;
          }
          if(numGroup==1)
          {
            for (int i = 0; i < sizeFamily; i++)
            {
                if(groupFamily[i].name==n)
                {
                    IndexItem=i;
                    break;
                }
            }
          }
          else if(numGroup==2)
          {
            for (int i = 0; i < sizeWork; i++)
            {
                if(groupWork[i].name==n)
                {
                    IndexItem=i;
                    break;
                }
            }
          }
          if(numGroup==3)
          {
            for (int i = 0; i < sizeFriend; i++)
            {
                if(groupFreind[i].name==n)
                {
                    IndexItem=i;
                    break;
                }
            }
          }
            if(IndexItem!=-1)
            {
                cout<<"item is found "<<endl;
                return IndexItem;
            }

            cout<<"item is not found "<<endl;
            return -1;


        }
        void deleteItemFromGroup(int numGruop,string name)
{


            int index=searchItemFromGroup(numGruop,name);
            if(index!=-1)
            {
                if(numGruop==1)
        {


          for (int i=index;i<sizeFamily; i++)
          {
            groupFamily[i]=groupFamily[i+1];
          }
          cout<<"removed succssefly"<<endl;
          return;
        }

           else if(numGruop==2)
         {


          for (int i=index;i<sizeWork; i++)
          {
            groupWork[i]=groupWork[i+1];
          }
          cout<<"removed succssefly"<<endl;
          return;
        }
         else if(numGruop==3)
         {


          for (int i=index;i<sizeFriend; i++)
          {
            groupFreind[i]=groupFreind[i+1];
          }
          cout<<"removed successfully"<<endl;
          return;
        }
    }
    else{
        cout<<"item is not found"<<endl;
    }
}




   void findRecord(string name)
{
    person searchRecord,foundRecord;
    searchRecord.name=name;
    foundRecord=namesAndNumbers->findNode(searchRecord);
    if(foundRecord.name==name)
    {
        cout<<"=============================================================================="<<endl;
            cout<<"============================ found record ================================"<<endl;
            cout<<"=============================================================================="<<endl;
      cout<<"name : "<<foundRecord.name<<" - "<<"phone number: " <<foundRecord.phoneNumber<<endl;
    }
    else
    {
        cout<<"There is no record"<<endl;
    }
}
void removeRecord(string name)
{
    person d;
    d.name=name;
int pos=namesAndNumbers->getposition(d);
if(pos!=-1)
{
    namesAndNumbers->removeAtPos(pos);
    cout<<"Record for "<<name<<" removed successfully"<<endl;
}
else
{
    cout<<"Record for "<<name<<" not found"<<endl;
}
}
void printLog()
{

    cout<<"==============================================="<<endl;
    cout<<"=================== RECORD LOG ================"<<endl;
    cout<<"==============================================="<<endl;
    callRecords->printStack();
}

  void makeCall(string phoneNum) {
    person searchRecord;
    searchRecord.phoneNumber = phoneNum;
    person foundRecord = namesAndNumbers->findNode(searchRecord);

    if (foundRecord.phoneNumber == phoneNum) {
        callRecords->push(foundRecord);
        cout << "Connected successfully."<<endl;;
    } else {
        foundRecord.phoneNumber=phoneNum;
        foundRecord.name="Undefined";
        callRecords->push(foundRecord);
        cout << "connected successfuly" << endl;
    }
}

void receiveCall(string phoneNum) {
    person searchRecord;
    searchRecord.phoneNumber = phoneNum;
    person foundRecord = namesAndNumbers->findNode(searchRecord);

    if (foundRecord.phoneNumber == phoneNum) {
        callRecords->push(foundRecord);
        cout << "The call was received successfully. "<<endl;
    } else {
        foundRecord.phoneNumber=phoneNum;
        foundRecord.name="Undefined";

        callRecords->push(foundRecord);
        cout<<"The call was received successfully. "<<endl;
    }
}

void notes(string note)
{
    requestQueue->enqueue(note);
}
void processRequest()
{
    if(requestQueue->isEmpty())
    {
        cout<<"not any notes for process it"<<endl;
        return;
    }
        requestQueue->dequeue();
    }

};
int main()
{
  integreatedProject one;
  person p;
  int choice;
  options:
  do
  {


  cout<<"\n\n\t\tTELEPHONE BOOK PROGRAM\n\n"<<
  "\t*******************************************\n"
  <<"\n\n\t\tWHAT DO YOU WANT TO DO ??\n\n"<<
  "\t****************************************\n"
  <<"\t*\t 1- Add contact         *\n"
  <<"\t*\t 2- create a call         *\n"
  <<"\t*\t 3- receiving a call      *\n"
  <<"\t*\t 4- add to group         *\n"
  <<"\t*\t 5- log display         *\n"
  <<"\t*\t 6- add note         *\n"
  <<"\t*\t 7- find a record         *\n"
  <<"\t*\t 8- remove record         *\n"
  <<"\t*\t 9- delete item from group         *\n"
  <<"\t*\t 10- proccessor note        *\n"
  <<"\t*\t 11- search item from group         *\n"
  <<"\t*\t 12- print a group log         *\n"
  <<"\t*\t 13- EXIT PROGRAM         *\n";
  cin>>choice;

  if(choice==1){
  cout<<"enter name \n";
  cin>>p.name;
  cout<<"enter number phone\n";
  cin>>p.phoneNumber;
  one.addRecord(p.name,p.phoneNumber);

  }

else if(choice==2){
cout<<"enter Number"<<endl;
cin>>p.phoneNumber;
one.makeCall(p.phoneNumber);

}
else if(choice==3)
{
cout<<"enter Number"<<endl;
cin>>p.phoneNumber;
one.receiveCall(p.phoneNumber);

}
else if(choice==4){
int select;
cout<<"selec name group 1-family group ,2-friend group,3-work group"<<endl;
cin>>select;
cout<<"enter name \n";
cin>>p.name;
cout<<"enter number\n";
cin>>p.phoneNumber;
one.addToGroup(select,p.name,p.phoneNumber);

}
else if(choice==5){
one.printLog();

}
else if(choice==6){
string n;
cout<<"enter your note"<<endl;
cin>>n;
one.notes(n);

}
else if(choice==7){
cout<<"enter name for find it"<<endl;
cin>>p.name;
one.findRecord(p.name);

}
else if(choice==8){
cout<<"enter name record for remove it"<<endl;
cin>>p.name;
one.removeRecord(p.name);

}
else if(choice==9){
    int select;
cout<<"selec name group 1-family group ,2-friend group,3-work group"<<endl;
cin>>select;
cout<<"enter name record for remove it"<<endl;
cin>>p.name;
one.deleteItemFromGroup(select,p.name);

}
else if(choice==10){
cout<<"procceor note"<<endl;
one.processRequest();

}
else if(choice==11){
    int select;
cout<<"selec name group 1-family group ,2-friend group,3-work group"<<endl;
cin>>select;
cout<<"enter name for search it in group"<<endl;
cin>>p.name;
one.searchItemFromGroup(select,p.name);

}
else if(choice==12){
    int select;
cout<<"selec name group 1-family group ,2-friend group,3-work group for print items"<<endl;
cin>>select;
one.printGroubLog(select);
}

}while (choice!=13);


  return 0;
}
