typedef struct {
  int* data;
  int  length;
  int  capacity;
} Vec;

Vec* vec_new() {
  Vec vec;
  vec.data = NULL;
  vec.length = 0;
  vec.capacity = 1;
  return &vec;
}

void vec_resize(Vec* vec) {
  int new_capacity = vec->capacity * 2;

  int* new_data = (int*) malloc(new_capacity);
  assert(new_data != NULL);

  for (int i = 0; i < vec->length; ++i) {
    new_data[i] = vec->data[i];
  }

  vec->data = new_data;
  vec->capacity = new_capacity;
}

void vec_push(Vec* vec, int n) {
  if (vec->length == vec->capacity) {
    vec_resize(vec);
  }

  vec->data[vec->length] = n;
  ++vec->length;
}

void vec_free(Vec* vec) {
  free(vec);
  free(vec->data);
}

int main() {
  Vec* vec = vec_new();
  vec_push(vec, 107);

  int* n = &vec->data[0];
  vec_push(vec, 110);
  printf("%d\n", *n);

  free(vec->data);
  vec_free(vec);
  return 0;
}
