// We expect to see that x = 7 after calling main.
int x;

void p() {
  x = x + 1;
}

int main() {
  x = 5;
  p();
  p();
}