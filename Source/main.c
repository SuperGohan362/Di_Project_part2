#include "./Initializer/Argument_Manager/Argument_Manager.h"
#include "./Initializer/Table_Allocator/Table_Allocator.h"
#include "./Work_Executor/Work_Executor.h"

#include "Query_execution/Preparator/Preparator.h"
#include "Query_execution/Query_executor/Query_Executor.h"
#include "Query_execution/Query_parser/Query_parser.h"



int main(int argc, char** argv){
  Arg_Manager_Ptr Manager = Create_ArgManager(argc,argv);
  Argument_Data_Ptr Arg_Data = Get_Argument_Data(Manager);


  Table_AllocatorPtr Table_Allocator = Create_Table_Allocator(Arg_Data);
  Table_Ptr Table = Allocate_Table(Table_Allocator);
  Fill_Table(Table, Table_Allocator);
  Print_Table(Table);

//  Read_Work_File(Arg_Data, Table);

  Start_Work(Table, Arg_Data);

  Delete_ArgManager(Manager);
  Delete_Argument_Data(Arg_Data);
  Delete_Table_Allocator(Table_Allocator);
  Delete_Table(Table);
}

