#include "Driver.h"
#include "ToyotaCar.h"

int main() {
  auto car = std::make_unique<ToyotaCar>("Aida");
  Driver person(std::move(car));
  person.pressDown();
}
