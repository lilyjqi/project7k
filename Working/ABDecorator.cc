#include "ABDecorator.h"

using namespace std;

ABDecorator::ABDecorator(AcadBuilding *ab): AcadBuilding(ab->getName(), ab->getIndex(), ab->getRow(), ab->getCol(), ab->getmonoBlock()), ab(ab) {}

ABDecorator::~ABDecorator() {}
