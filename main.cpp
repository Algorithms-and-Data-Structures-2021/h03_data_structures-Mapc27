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
//  queue.Dequeue();
  queue.Clear();
  return 0;
}