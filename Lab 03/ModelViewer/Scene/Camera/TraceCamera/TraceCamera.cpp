//
// Created by Кирилл Воробьев on 01.06.2024.
//

#include "TraceCamera.h"

void TraceCamera::accept(VisitorBase &v) {
    return v.visitCamera(*this);
}
