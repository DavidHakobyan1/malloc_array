#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef double element_type;
typedef unsigned int size_type;

struct array_t
{
	element_type* start;
	size_type size;
};

typedef struct array_t array;

array* array_create(size_type n, element_type default_value){
	array* a = (array*)malloc(sizeof(array));
	a->size = n;
	a->start = (element_type*)malloc(n * sizeof(element_type));
	for (size_type i = 0; i < a->size; ++i)  {
		a->start[i] = default_value;
	}
	return a;
}

void array_insert(array* a, size_type index, element_type value){
	assert(index >= 0);
	assert(index <= a->size);
	a->size = a->size + 1;
	element_type* tmp = (element_type*)malloc(a->size * sizeof(element_type));
	for (size_type i = 0; i < index; ++i) {
		tmp[i] = a->start[i];
	}
	tmp[index] = value;
	for (size_type i = index + 1; i < a->size; ++i) {
		tmp[i] = a->start[i - 1];
	}
	free(a->start);
	a->start = tmp;
}

size_type array_size(array* a){
	return a->size;
}

element_type array_access(array* a, size_type index){
	assert(index >= 0);
	assert(index < a->size);
	return a->start[index];
}

void array_delete(array* a){
	printf("%f\n", a->start[0]);
	free(a);
	printf("%f\n", a->start[0]);
}

int main(){
	array* a = array_create(4, 0);
	array_insert(a, array_size(a), 8);
	array_insert(a, array_size(a), 8);
	for (size_type count = 0; count < 2; ++count) {
		array_insert(a, array_size(a), 7);
	}
	array_insert(a, 0, 5);
	array_insert(a, 5, 15);
	for (size_type i = 0; i < a->size; ++i)  {
		printf("a[%d] = %f\n", i, array_access(a, i));
	}	
	array_delete(a);
	
	return 0;
}
