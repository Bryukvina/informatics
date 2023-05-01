#include <iostream>
#include <iterator>
#include <memory>

struct Node{
    std::shared_ptr<Node> parent;
    std::shared_ptr<Node> child1;
    std::shared_ptr<Node> child2;
    int value;

    Node(const int&value): value(value){};

    ~Node(){
        std::cout << "delete" << value << std::endl;
        ~value;
    };

};

class Tree{
    public:
        std::shared_ptr<Node> head;
        std::shared_ptr<Node> current_place;

        Tree(const int& value){
            head = std::make_shared<Node>(value);
            current_place = head;
        };
        
        int& get_value() {
            std::cout << current_place->value << std::endl;
            return current_place->value;};

        void left() {
            current_place = current_place->child1;
        };

        void right(){
            current_place = current_place->child2;
        };

        void up(){
            current_place = (current_place->parent);
        };

        void append1(const int& val) {
            current_place->child1 = std::make_shared<Node>(val);
            current_place->child1->parent = std::shared_ptr<Node>(current_place);
        };

        void append2(const int& val) {
            current_place->child2 = std::make_shared<Node>(val);
            current_place->child2->parent = std::shared_ptr<Node>(current_place);
        };
};

int main(){
    Tree tree(0);
    tree.append1(1);
    tree.append2(2);
    tree.right();
    tree.append1(5);
    tree.append2(6);
    tree.up();
    tree.get_value();
    tree.append1(7);
    tree.get_value();
    tree.up();
    tree.up();
    tree.get_value();
};
