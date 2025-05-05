// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
template<typename T>
class TPQueue {
 private:
  struct Node {
    T obj;
    Node* next;
    explicit Node(const T& val) : obj(val), next(nullptr) {}
  };
  Node* head = nullptr;

 public:
  ~TPQueue() {
    while (head) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }
  void push(const T& obj) {
    Node* tp_node = new Node(obj);
    if (!head || obj.prior > head->obj.prior) {
      tp_node->next = head;
      head = tp_node;
    } else {
        Node* cur = head;
        while (cur->next && cur->next->obj.prior >= obj.prior) cur = cur->next;
        tp_node->next = cur->next;
        cur->next = tp_node;
    }
  }
  T pop() {
    if (!head) {
      throw "Is empty!";
    }
    Node* temp = head;
    T t_obj = head->obj;
    head = head->next;
    delete temp;
    return t_obj;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
