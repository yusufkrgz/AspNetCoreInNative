#include "pch.h"
#include "CLI.h"

using namespace ASP;
using namespace System;
using namespace System::IO;
using namespace System::Security;
using namespace System::Reflection;


namespace CLI
{

public ref class API
{
public:
  static void CallNET5()
  {
    ASP::Program::Main(nullptr);
  }
};

static Assembly ^OnAssemblyResolve(System::Object ^, System::ResolveEventArgs ^args)
{
  try
  {
    auto assemblyPath = Path::GetDirectoryName(Assembly::GetExecutingAssembly()->Location);
    auto assemblyFile = assemblyPath + L"\\" + args->Name->Split(L',')[0] + L".dll";

    return Assembly::LoadFrom(assemblyFile);
  }
  catch (Exception ^)
  {
    return nullptr;
  }
}


void CallNET5()
{
  AppDomain::CurrentDomain->AssemblyResolve += gcnew System::ResolveEventHandler(&OnAssemblyResolve);

  ASP::Program::Main(nullptr);
}

}
