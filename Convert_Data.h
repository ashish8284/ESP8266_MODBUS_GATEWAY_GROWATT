float InttoFloat(uint16_t Data0,uint16_t Data1) {
  float x;
  unsigned long *p;
  p = (unsigned long*)&x;
  *p = (unsigned long)Data0 << 16 | Data1;
  return(x);
}

unsigned long InttoDint(uint16_t Data0,uint16_t Data1) {
  unsigned long x;
  unsigned long *p;
  p = (unsigned long*)&x;
  *p = (unsigned long)Data0 << 16 | Data1;
  return(x);
}
