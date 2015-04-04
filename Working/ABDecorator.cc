#include "ABDecorator.h"

using namespace std;

ABDecorator::ABDecorator(AcadBuilding *ab): AcadBuilding(ab->getName(), ab->getIndex(), ab->getRindex(), ab->getCindex(), ab->getmonoBlock()), ab(ab) {}

ABDecorator::~ABDecorator() {}
