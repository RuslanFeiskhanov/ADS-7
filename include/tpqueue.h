// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>

class TPQueue{
 private:
struct ITEM {
    T value;
    ITEM* next;
};
ITEM* next;
ITEM* tail;

 public:
    TPQueue() :tail(nullptr) {}

T pop() {
    ITEM* temp = tail;
    tail = tail->next;
    return (temp->value);
}

void push(T symb) {
    ITEM* head = tail;
    if (head == nullptr) {
        head = new ITEM;
        tail = head;
        head->value = symb;
        head->next = nullptr;
    } else {
        ITEM* elm = new ITEM;
        elm->value = symb;
        if (tail->value.prior < elm->value.prior) {
            elm->next = head;
            tail = elm;
        }
        while (head != nullptr) {
        if ((head->value.prior == elm->value.prior && (head->next == nullptr || head->next->value.prior < elm->value.prior))) {
            elm->next = head->next;
            head->next = elm;
        } else {
            if (head->value.prior > elm->value.prior) {
                if ((head->next != nullptr && head->next->value.prior < elm->value.prior)) {
                    elm->next = head->next;
                    head->next = elm;  
                } else {
                    if (head->next == nullptr) {
                        elm->next = head->next;
                        head->next = elm;
                    }
                } 
            }
        }
        head = head->next;
        }
    }
}
};
struct SYM {
    char ch;
    int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
