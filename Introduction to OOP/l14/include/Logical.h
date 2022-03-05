#pragma once

class TwoArg {
    public:
    bool virtual result(bool a, bool b) const = 0;
};

class OR : public TwoArg {
    public:
    bool result(bool a, bool b) const {
        return a || b;
    }
};

class AND : public TwoArg {
    public:
    bool result(bool a, bool b) const {
        return a && b;
    }
};

class OneArg {
    public:
    bool virtual result(bool a) const  = 0;;

};

class NOT : public OneArg {
    public:
    bool result(bool a) const {
        return !a;
    }
};

class Logical {
    public:
    bool static eval(const OneArg &op, bool a) {
        return op.result(a);
    }
    bool static eval(const TwoArg &op, bool a, bool b) {
        return op.result(a,b);
    }
};