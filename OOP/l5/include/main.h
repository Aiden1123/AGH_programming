#pragma once
#include "objects.h"
#include "abstract.h"

void draw(const Drawable *d) {
    d->draw();
}
