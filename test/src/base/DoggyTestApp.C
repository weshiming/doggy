//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "DoggyTestApp.h"
#include "DoggyApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
DoggyTestApp::validParams()
{
  InputParameters params = DoggyApp::validParams();
  return params;
}

DoggyTestApp::DoggyTestApp(InputParameters parameters) : MooseApp(parameters)
{
  DoggyTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

DoggyTestApp::~DoggyTestApp() {}

void
DoggyTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  DoggyApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"DoggyTestApp"});
    Registry::registerActionsTo(af, {"DoggyTestApp"});
  }
}

void
DoggyTestApp::registerApps()
{
  registerApp(DoggyApp);
  registerApp(DoggyTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
DoggyTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  DoggyTestApp::registerAll(f, af, s);
}
extern "C" void
DoggyTestApp__registerApps()
{
  DoggyTestApp::registerApps();
}
