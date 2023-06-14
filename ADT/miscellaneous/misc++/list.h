#pragma once


template<typename T>
class list {

    private:
        class Node {
            public:
                T data;
                Node* prev, *next;

                Node(T& data) : data(data), prev(NULL), next(NULL) {};
                
        };

        Node *head_, *tail_;

    public:
        void create();
        void create(T);
        void insertAtFront(T);
        void display();

        bool empty() {
            if(this->head_ == NULL) return true;
            return false;
        }
};


template<typename T>
void list<T>::create() {
    // creates 0-length linked list
    head_ = NULL;
    tail_ = NULL;
}

template<typename T>
void list<T>::create(T data) {
    //create 1-length linked list
    Node *node = new Node(data);
    this->head_ = node;
    this->tail_ = node;
}

template<typename T>
void list<T>::insertAtFront(T data) {
    Node *node = new Node(data);
    head_->prev = node;
    node->next = head_;
    head_ = node;
}

template<typename T>
void list<T>::display() {
      Node *monke = this->head_;
      if(this->empty()) std::cout<<"\nList is empty.";
      else {
        std::cout<<"[ ";
        
        while(monke != NULL) {
            std::cout<<monke->data;
            if(monke->next != NULL) std::cout<<", ";
            monke = monke->next;
        }

        std::cout<<" ]";
      }
}
