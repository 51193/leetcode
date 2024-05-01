#include<iostream>
#include<unordered_map>

class LRUCache {
public:
    LRUCache(int capacity)
    :capacity{capacity} {
        this->head=new Node;
        this->tail=new Node;
        this->head->next=tail;
        this->tail->prev=head;
    }

    ~LRUCache(){
        while(head->next!=nullptr){
            Node* n=head->next;
            head->next=n->next;
            delete n;
        }
    }
    
    int get(int key) {
        Node* node=searchNode(key);
        if(node){
            this->moveNodetoHead(node);
            return node->value;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        Node* node=searchNode(key);
        if(node){
            this->updateNode(node, value);
            this->moveNodetoHead(node);
        }
        else{
            addNode(key, value);
        }
    }

private:

    struct Node{
        public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node()
        :key{-1}, value{0}, prev{nullptr}, next{nullptr}{}

        Node(int key, int value, Node* prev, Node* next)
        :key{key}, value{value}, prev{prev}, next{next}{}
    };

    int capacity;
    Node* head;
    Node* tail;
    std::unordered_map<int, Node*> nodes;
    
    void addNode(int key, int value){

        if(this->nodes.size()==capacity){

            Node* toDelete=this->tail->prev;

            this->tail->prev=this->tail->prev->prev;
            this->tail->prev->next=this->tail;

            this->nodes.erase(toDelete->key);
            delete toDelete;
        }

        Node* node=new Node;
        node->key=key;
        node->value=value;
        node->next=this->head->next;
        this->head->next->prev=node; 
        this->head->next=node;
        node->prev=this->head;

        this->nodes[key]=node;
    }

    Node* searchNode(int key){

        auto it_nodes=this->nodes.find(key);

        if(it_nodes==this->nodes.end()){
            return nullptr;
        }
        else{
            return (*it_nodes).second;
        }
    }

    void moveNodetoHead(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;

        this->head->next->prev=node;
        node->next=this->head->next;
        this->head->next=node;
        node->prev=this->head;
    }

    void updateNode(Node* node, int value){
        if(node){
            node->value=value;
        }
    }
};


int main(){
    LRUCache test(2);
    test.put(1,1);
    test.put(2,2);
    std::cout<<test.get(1)<<std::endl;
    test.put(3,3);
    std::cout<<test.get(2)<<std::endl;
    test.put(4,4);
    std::cout<<test.get(1)<<std::endl;
    std::cout<<test.get(3)<<std::endl;
    std::cout<<test.get(4)<<std::endl;
}