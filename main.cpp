#include <iostream>

#include "array_stack.hpp"
#include "linked_stack.hpp"
#include "linked_queue.hpp"

using namespace itis;

int main() {

  LinkedQueue queue;
  queue.Enqueue(Element::BMW);
  queue.Enqueue(Element::BMW);
  queue.Enqueue(Element::BMW);
  for(int i = 0; i < 3; i++) {
      queue.Dequeue();
  }
  return 0;
}