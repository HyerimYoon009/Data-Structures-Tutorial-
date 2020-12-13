#ifndef STACK_H
#define STACK_H
#include <iostream>

const int STACK_CAPACITY = 5;

// Returns `true` if the stack is emtpy, else `false`
bool stack_empty(int* stack, int& stack_size) {
  return stack_size <= 0;
}

// Returns `true` if the stack if full, else `false`
bool stack_full(int* stack, int& stack_size) {
  return stack_size == STACK_CAPACITY; 
}

void stack_push(int* stack, int& stack_size, int num) {

  if (!stack_full(stack, stack_size)) {
    stack[stack_size] = num; 
    stack_size++;
  
  } else {
    std::cout << "The stack is full!" << std::endl;
  }
}

int stack_pop(int* stack, int& stack_size) {
  if (!stack_empty(stack, stack_size)) {
    int original_value = stack[stack_size - 1];
    stack[stack_size - 1] = 0; 
    stack_size--; 
    return original_value;
  }
  std::cout << "The stack is empty!" << std::endl;
  return -1; 
}

int stack_peep(int* stack, int& stack_size) {
  if (stack_empty(stack, stack_size)) {
    std::cout << "The stack is empty!" << std::endl;
    return -1;
  }
  return stack[stack_size - 1];
}

void stack_print(int* stack, int& stack_size) {
  std::cout << stack_size << " values in the stack: " << std::endl;
  for (int i = 0; i < stack_size; i++) {
    std::cout << "\t" << i+1 << ". " << stack[i] << std::endl;
  }
}

void test_stack() {
  int stack[STACK_CAPACITY] = {0};
  int stack_size = 0;

  // Testing pushing onto the stack
  std::cout << "--- TEST PUSHING ONTO THE STACK ---" << std::endl;
  stack_push(stack, stack_size, 100);
  stack_push(stack, stack_size, 200);
  stack_push(stack, stack_size, 300);

  stack_print(stack, stack_size);

  // Testing popping from the stack 
  std::cout << "--- TEST POPPING FROM THE STACK ---" << std::endl;
  int popped = stack_pop(stack, stack_size);
  std::cout << "Value retrieved from popping stack: " << popped << std::endl;
  stack_print(stack, stack_size);

  // Testing peeping the stack 
  std::cout << "--- TEST PEEPING THE STACK ---" << std::endl;
  int peeped = stack_peep(stack, stack_size);
  std::cout << "Value retrieved from peeing stack: " << peeped << std::endl;
  stack_print(stack, stack_size);

  // Remove everything from the stack 
  while (!stack_empty(stack, stack_size)) {
    stack_pop(stack, stack_size);
  }

  // Testing popping and peeping from the stack 
  std::cout << "--- TEST POPPING FROM EMPTY STACK ---" << std::endl;
  stack_pop(stack, stack_size);
  stack_peep(stack, stack_size);

  // Add until the stack if stack_full
  while (!stack_full(stack, stack_size)) {
    stack_push(stack, stack_size, 7777);
  }

  // Test pushing to a full stack 
  std::cout << "--- TEST PUSHING TO A FULL STACK ---" << std::endl;
  stack_push(stack, stack_size, 8888);
}

#endif