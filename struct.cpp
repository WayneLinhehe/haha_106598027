#include "struct.h"
#include "iterator.h"
Iterator<Term*> * Struct::createIterator()
{
  //return new StructIterator(this);
}

Iterator<Term*> * Struct::createDFSIterator()
{
  return new StructIterator1(this);
}

Iterator<Term*> * Struct::createBFSIterator()
{
  return new StructIterator2(this);
}
