int c() {
  int* c = 0;
  printf("About to crash....\n");
  *c = 4;
  return *c;
}

int b() {
  int dd = 44;
  return c();
}

int a() {
  int cc = 33;
  return b();
}

int main() {
  int ma = 3;
  int mb = 4;
  a();
  return 2;
}

