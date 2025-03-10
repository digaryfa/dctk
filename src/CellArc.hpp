#ifndef DCTK_CELLARC_HPP_
#define DCTK_CELLARC_HPP_

#include <string>
#include <vector>
#include "CellPin.hpp"
#include "si2dr_liberty.h"

namespace dctk {

class CellPin;

class CellArc {

public:

    CellArc(CellPin* pin, std::string& related_pin_str);
    ~CellArc();

    void update_related_pin(CellPin* pin) {
        _related_pin = pin;
    }

    // TODO:  change to enum
    void set_timing_type(std::string& s) {
        _timing_type_str = s;
    }
    void set_timing_sense(std::string& s) {
        _timing_sense_str = s;
    }

    // NLDM tables
    void set_cell_rise_table(liberty_value_data* d) {
        _cell_rise_table = d;
    }
    void set_cell_fall_table(liberty_value_data* d) {
        _cell_fall_table = d;
    }
    void set_rise_transition_table(liberty_value_data* d) {
        _rise_transition_table = d;
    }
    void set_fall_transition_table(liberty_value_data* d) {
        _fall_transition_table = d;
    }

    // Receiver Capacitance tables
    void set_receiver_capacitance1_fall_table(liberty_value_data* d) {
        _receiver_capacitance1_fall_table = d;
    }
    void set_receiver_capacitance1_rise_table(liberty_value_data* d) {
        _receiver_capacitance1_rise_table = d;
    }
    void set_receiver_capacitance2_fall_table(liberty_value_data* d) {
        _receiver_capacitance1_fall_table = d;
    }
    void set_receiver_capacitance2_rise_table(liberty_value_data* d) {
        _receiver_capacitance1_rise_table = d;
    }

    // CCS tables
    void add_current_rise_table(liberty_value_data* d);
    void add_current_fall_table(liberty_value_data* d);

    // debug
    void dump();

private:

    friend class Cell;

    CellPin* _pin;
    CellPin* _related_pin;

    // TODO: change the following into enum to save space and run faster
    std::string _timing_type_str;
    std::string _timing_sense_str;

    // temp location for unresolved related pins
    std::string _related_pin_str;

    // NLDM tables
    liberty_value_data* _cell_rise_table;
    liberty_value_data* _cell_fall_table;
    liberty_value_data* _rise_transition_table;
    liberty_value_data* _fall_transition_table;

    // Receiver Capacitance tables
    liberty_value_data* _receiver_capacitance1_fall_table;
    liberty_value_data* _receiver_capacitance1_rise_table;
    liberty_value_data* _receiver_capacitance2_fall_table;
    liberty_value_data* _receiver_capacitance2_rise_table;

    // CCS tables
    // TODO:  replace vector with array of pointers.
    std::vector<liberty_value_data*> _output_current_rise_tables;
    std::vector<liberty_value_data*> _output_current_fall_tables;

};
};

#endif
