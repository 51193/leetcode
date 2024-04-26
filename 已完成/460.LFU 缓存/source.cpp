#include<unordered_map>
#include<iostream>

//运行时间击败98.49%，无敌了

class Node{
public:
    Node* next;
    Node* prev;
    int key;
    int value;

    Node()
    :next{ nullptr }, prev{ nullptr },
    key{ -1 }, value{ 0 } {}

    Node( Node* next, Node* prev, int key, int value)
    :next{ next }, prev{ prev },
    key{ key }, value{ value } {}
};

class Node_endpoint
:public Node{
public:
    Node_endpoint* up;
    Node_endpoint* down;
    int frequency;

    Node_endpoint* counterpart;

    Node_endpoint(int frequency, Node_endpoint* head)
    :up{ nullptr }, down{ nullptr },
    frequency{ frequency }, counterpart{ head } {
        this->prev = this->counterpart;
    }

    Node_endpoint()
    :up{ nullptr }, down{ nullptr },
    frequency{ -1 }, counterpart{ nullptr } {}

    Node_endpoint(Node_endpoint* up, Node_endpoint* down, int frequency)
    :up{ up }, down{ down },
    frequency{ frequency }, counterpart{ nullptr } {
        this->counterpart = new Node_endpoint(this->frequency, this);

        this->next = this->counterpart;

        this->up->down = this;
        if(down) this->down->up = this;
    }
};

struct NodePair
{
    Node_endpoint* head;
    Node* node;

    NodePair()
    :head{ nullptr }, node{ nullptr } {}

    NodePair(Node_endpoint* head, Node* node)
    :head{ head }, node{ node } {}
};


class LFUCache {
public:
    LFUCache(int capacity)
    :capacity{ capacity } {
        this->head = new Node_endpoint();
    }
    
    int get(int key) {
        if(this->searchNode(key)){
            this->moveNode(key);
            return this->searchNode(key)->node->value;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(this->searchNode(key)) {
            this->searchNode(key)->node->value = value;
            this->moveNode(key);
        }
        else{
            this->addNode(key, value);
        }
    }

//private:
    int capacity;
    Node_endpoint* head;

    std::unordered_map<int, NodePair> nodes;

    NodePair* searchNode(int key) {
        auto it_nodes = this->nodes.find(key);

        if(it_nodes == this->nodes.end()) {
            return nullptr;
        }
        else {
            return &((*it_nodes).second);
        }
    }

    Node_endpoint* insertEndpoint() {
        if(this->head->down && this->head->down->frequency == 1) return this->head->down;
        else return new Node_endpoint(this->head, this->head->down, 1);
    }

    void addNode(int key, int value) {

        if(this->nodes.size() == capacity) {
            Node* toDelete = nullptr;
            if(this->head->down->next != this->head->down->counterpart) toDelete = this->head->down->counterpart->prev;
            else toDelete = this->head->down->down->counterpart->prev;

            if(toDelete->prev == this->head->down && this->head->down->frequency != 1) {
                Node_endpoint* toDelete_endpoint = this->head->down;
                toDelete_endpoint->down->up = this->head;
                this->head->down = toDelete_endpoint->down;

                this->nodes.erase(toDelete->key);
                delete toDelete;
                delete toDelete_endpoint->counterpart;
                delete toDelete_endpoint;
            }
            else {
                toDelete->prev->next = toDelete->next;
                toDelete->next->prev = toDelete->prev;

                this->nodes.erase(toDelete->key);
                delete toDelete;
            }
        }

        Node_endpoint* endpoint = insertEndpoint();

        Node* node = new Node;
        node->key = key;
        node->value = value;
        node->next = endpoint->next;
        endpoint->next->prev = node; 
        endpoint->next = node;
        node->prev = endpoint;

        this->nodes[key] = NodePair(endpoint, node);
    }

    void moveNode(int key){
        NodePair* node_pair = this->searchNode(key);
        if(node_pair) {

                node_pair->node->next->prev = node_pair->node->prev;
                node_pair->node->prev->next = node_pair->node->next;
                
            if(node_pair->head->down && node_pair->head->down->frequency == node_pair->head->frequency + 1) {

                if(node_pair->head->next == node_pair->head->counterpart){
                    Node_endpoint* toDelete = node_pair->head;
                    node_pair->head = node_pair->head->down;

                    toDelete->up->down = toDelete->down;
                    toDelete->down->up = toDelete->up;

                    delete toDelete->counterpart;
                    delete toDelete;
                }
                else{
                    node_pair->head = node_pair->head->down;
                }

                node_pair->node->next = node_pair->head->next;
                node_pair->node->prev = node_pair->head;

                node_pair->node->next->prev = node_pair->node;
                node_pair->head->next = node_pair->node;
            }
            else{
                
                node_pair->head = new Node_endpoint(node_pair->head, node_pair->head->down, node_pair->head->frequency + 1);

                node_pair->node->next = node_pair->head->next;
                node_pair->node->prev = node_pair->head;

                node_pair->head->next = node_pair->node;
                node_pair->head->counterpart->prev = node_pair->node;

            }
        }
    }
};

int main() {

    LFUCache test(1);

    test.addNode(2, 1);
    std::cout << test.get(2) << std::endl;
    test.addNode(3, 2);
    std::cout << test.get(2) << std::endl;
    std::cout << test.get(3) << std::endl;

    std::cout << std::endl;

    Node_endpoint* head = test.head;

    while(head->down != nullptr){
        head = head->down;
        Node* node = head->next;

        while(node != head->counterpart){
            std::cout << node->key << ":" << node->value << " ";
            node = node->next;
        }

        std::cout << std::endl;

    }
}