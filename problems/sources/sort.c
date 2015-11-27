#include <stdio.h>
#include <stdlib.h>

void shell_sort(void **array, int n, int (*cmp)(const void*, const void*)) {
  int h = n;
  while(h /= 2){
    int i;
    for(i = h; i < n; i++){
      void * p = array[i];
      int j;
      for(j = i; j >= h && (cmp(p, array[j - h]) == -1); j -=h){
        array[j] = array[j - h];
      }
      array[j] = p;
    }
  }
}

void bubble_sort(void **array, int n, int (*cmp)(const void*, const void*)){
  int i;
  for(i = 0; i < n; i++){
    int j;
    for(j = i + 1; j < n; j++){
      if(cmp(array[i], array[j]) != -1){
        void * t = array[i];
        array[i] = array[j];
        array[j] = t;
      }
    }
  }
}

void selection_sort(void **array, int n,  int (*cmp)(const void*, const void*)){
  int i;
  for(i = 0; i < n; i++){
    int smallest = i;
    int j;
    for(j = i + 1; j < n; j++){
      if(cmp(array[smallest], array[j]) != -1){
        smallest = j;
      }
    }
    if(i != smallest){
      void * t = array[i];
      array[i] = array[smallest];
      array[smallest] = t;
    }
  }
}

void insertion_sort(void **array, int n,  int (*cmp)(const void*, const void*)){
  int i;
  for (i = 1; i < n; i++) {
    void* t = array[i];
    int j;
    for (j = i; j > 0 && (cmp(t, array[j - 1]) == -1); j--) {
      array[j] = array[j - 1];
    }
    array[j] = t;
  }
}

void gnome_sort(void **array, int n,  int (*cmp)(const void*, const void*)){
  int i = 1, j = 2;
  while(i < n) {
    if (cmp(array[i] ,array[i - 1]) == -1) {
      void * t = array[i-1];
      array[i -1] = array[i];
      array[i] = t;
    }
    if (--i != 0){
      i = j++;
    }
  }
}

void pancake_sort(void **array, int n,  int (*cmp)(const void*, const void*)){
  void do_flip(void **array, int n, int x){
    void* swap;
    int i;
    for(i = 0 ; i < --x; i++){
      swap = array[i];
      array[i] = array[x];
      array[x] = swap;
    }
  }
  if(n < 2){
    return;
  }
  int i;
  for(i = n; i > 1; i--){
    int max_num_pos = 0;
    int j;
    for(j = 0; j < i; j++) {
      if(cmp(array[max_num_pos], array[j]) == -1){
        max_num_pos = j;
      }
    }

    if(max_num_pos != (i - 1)){
      if(max_num_pos){
        do_flip(array, n, max_num_pos+1);
      }
      do_flip(array, n, i);
    }
  }
}

void cocktail_sort(void **array, int n,  int (*cmp)(const void*, const void*)){
	int t = 0;
	while (t == 0) {
    int i;
		for (i = 1, t = 1; i < n; i++){
      if (cmp(array[i], array[i - 1]) == -1){
         void * p = array[i];
         array[i] = array[i - 1];
         array[i - 1] = p;
         t = 0;
      }
    }
		if (t) break;
		for (i = n - 1, t = 1; i; i--){
      if (cmp(array[i], array[i - 1]) == -1){
         void * p = array[i];
         array[i] = array[i - 1];
         array[i - 1] = p;
         t = 0;
      }
    }
	}
}

void stooge_sort(void** array, int i, int j, int (*cmp)(const void*, const void*)){
   int t;
   if (cmp(array[j], array[i]) == -1){
      void * p = array[i];
      array[i] = array[j];
      array[j] = p;
   }
   if (j - i > 1)
   {
       t = (j - i + 1) / 3;
       stooge_sort(array, i, j - t, cmp);
       stooge_sort(array, i + t, j, cmp);
       stooge_sort(array, i, j - t, cmp);
   }
}
