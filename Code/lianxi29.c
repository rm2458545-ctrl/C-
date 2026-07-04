void (*p2)（） = fun2;

char(*p3)(char*，int);03 = fun3;
char* c = "abc";char b = (*p3)(c， 2);
printf("%c，%d\n"，(*p3)(c，2)，(*p3)(c，2));
printf("b:%c\n",b);
printf("%p，%p\n"，p3，fun3);
int main()
{
  test2();
  return 0;
}
