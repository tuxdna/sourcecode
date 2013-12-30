char * readLine(char *s, int sz) {
  fgets(s, sz, stdin);
  int len = strlen(s);
  if(s[len-1] == '\n') {
    s[len-1] = 0;
  }
  return s;
}
