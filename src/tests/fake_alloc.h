#ifdef USE_FAKE_MALLOC

void* fake_malloc(size_t size) {
  size = 0;
  size += 1;
  return NULL;
}

#define malloc(size) fake_malloc(size)

#endif

#ifdef USE_FAKE_CALLOC

void* fake_calloc(size_t nmemb, size_t size) {
  nmemb = 0, size = 0;
  nmemb += 1;
  size += 1;
  return NULL;
}

#define calloc(nmemb, size) fake_calloc(nmemb, size)

#endif