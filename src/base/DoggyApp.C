#include "DoggyApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
DoggyApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

DoggyApp::DoggyApp(InputParameters parameters) : MooseApp(parameters)
{
  DoggyApp::registerAll(_factory, _action_factory, _syntax);
}

DoggyApp::~DoggyApp() {}

void
DoggyApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"DoggyApp"});
  Registry::registerActionsTo(af, {"DoggyApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
DoggyApp::registerApps()
{
  registerApp(DoggyApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
DoggyApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  DoggyApp::registerAll(f, af, s);
}
extern "C" void
DoggyApp__registerApps()
{
  DoggyApp::registerApps();
}
