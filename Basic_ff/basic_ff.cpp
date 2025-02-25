#include "systemc.h"
using namespace std;
SC_MODULE(basic_ff) {
    sc_in<bool> clk, d;
    sc_out<bool> q;

    void prc_basic_ff() {
        q.write(d.read());
        std::cout << " q: " << q.read() << " @ " << sc_time_stamp () << endl;
    }

    SC_CTOR(basic_ff) {
        SC_METHOD(prc_basic_ff);
        sensitive << clk.pos();
    }
};
