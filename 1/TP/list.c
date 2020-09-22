#include "head.h"

int main() {
  list L;
  createList(&L);
  char name[50], param[5];
  int skala, condition = 0;
  
  while(condition == 0){
    scanf("%s",name);
    if((strcmp(name,"desc") == 0) || (strcmp(name,"asc") == 0)){
      strcpy(param,name);
      break;
    }
    scanf("%d",&skala);
    
    addLast(name, skala, &L);
  }
  if(strcmp(name,"asc") == 0){
    sortAndPrintElement(1,L);
  }else{
    sortAndPrintElement(0,L);
  }

  // system("pause");
  return 0;
}