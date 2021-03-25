#include "linked_dequeue.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedDequeue::Enqueue(Element e) {
    // === РЕАЛИЗОВАНО ===
    DoublyNode *node = new DoublyNode(e, nullptr, nullptr);

    if(size_ == 0){
        front_ = node;
        back_ = node;
    } else{
        node->next = back_;
        back_->previous = node;
        back_ = node;
    }
    size_ += 1;
}

void LinkedDequeue::EnqueueFront(Element e) {
    // TODO: напишите здесь свой код ...
    DoublyNode *node = new DoublyNode(e, nullptr, nullptr);

    if(size_ == 0){
        front_ = node;
        back_ = node;
    }
    else {
        node->next = front_;
        front_->previous = node;
        front_ = node;
    }
    size_ += 1;
}

void LinkedDequeue::Dequeue() {
    // === РЕАЛИЗОВАНО ===
    if (size_ == 0) {
        throw std::logic_error("cannot not dequeue from empty queue");
    }

    // TODO: напишите здесь свой код ...
    DoublyNode *node = front_->previous;
    if(node != nullptr){
        delete front_;
        front_ = node;
        front_->next = nullptr;
    }
    else{
        delete front_;
        back_ = nullptr;
        front_ = nullptr;
    }
    size_ -= 1;
}

void LinkedDequeue::DequeueBack() {
    // === РЕАЛИЗОВАНО ===
    if (size_ == 0) {
        throw std::logic_error("cannot not dequeue from empty queue");
    }

    // TODO: напишите здесь свой код ...
    DoublyNode * node = back_->next;
    if(node != nullptr){
        delete back_;
        back_ = node;
        back_->previous = nullptr;
    }
    else{
        delete front_;
        back_ = nullptr;
        front_ = nullptr;
    }
    size_ -= 1;
}

void LinkedDequeue::Clear() {
    // TODO: напишите здесь свой код ...
    // === РЕАЛИЗОВАНО ===
    for(DoublyNode *current_node = front_; current_node != nullptr;){
        auto delete_node = current_node;
        current_node = current_node->previous;
        delete delete_node;
    }

    front_ = nullptr;
    back_ = nullptr;
    size_ = 0;
}

// === РЕАЛИЗОВАНО ===

LinkedDequeue::~LinkedDequeue() {
    Clear();
}

std::optional<Element> LinkedDequeue::front() const {
    return front_ == nullptr ? std::nullopt : std::make_optional(front_->data);
}

std::optional<Element> LinkedDequeue::back() const {
    return back_ == nullptr ? std::nullopt : std::make_optional(back_->data);
}

bool LinkedDequeue::IsEmpty() const {
    return size_ == 0;
}

int LinkedDequeue::size() const {
    return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedDequeue &queue) {
    os << "size: " << queue.size_ << '\n';
    for (auto current_node = queue.front_; current_node != nullptr; current_node = current_node->previous) {
        if (current_node == queue.front_) os << "[FRONT] ";
        if (current_node == queue.back_) os << "[BACK] ";
        os << enum2str(current_node->data) << '\n';
    }
    return os;
}

}  // namespace itis
