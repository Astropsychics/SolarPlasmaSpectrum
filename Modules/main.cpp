#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <vector>

using namespace std;

//Energy range (in keV)
double energy_start = 0.010;
double energy_end = 10.000;
double energy_step = 0.010;

int main(int argc, char *argv[]){

    //Input spectral width
    double width = 0;
    cout << "\n" << "Welcome to the Solar Spectrum Model. \n";
    cout << "Please input the desired peak width, in keV: " ;
    cin >> width;
    cout << endl;

    //Determines number of steps to perform based on energy start and end points
    //as well as the step size. Also creates an array of that size and
    //populates it with energies over thedesired range
    double energy = energy_start;
    int energy_row = (energy_end - energy_start)/energy_step + 1;

    vector<double> input_energy(energy_row, 0);

    for ( int x = 0; x < energy_row; x++ ){
        input_energy[x] = energy;
        energy = energy + energy_step; }


    //Reads in CHIANTI database
    fstream spectrum_file("../Inputs/CHIANTI_line_full.dat", fstream::in);

    int row;
    spectrum_file >> row;

    double spectrum_input[row][2];
    for( int i=0; i<row; i++ ){
        for( int j=0; j<2; j++ ){
            spectrum_file >> spectrum_input[i][j]; } }
    spectrum_file.close();

    double spectral_energy[row];
    double spectral_intensity[row];
    for (int l=0; l<row; l++){

        spectral_energy[l] = 12400.0/spectrum_input[l][0] /1000.0 ;
        //converts from Ang to keV
        spectral_intensity[l] = spectrum_input[l][1]; }

    //creates a solar spectrum and populates it with gaussians extracted from the
    //CHIANTI database
    vector<double> solar_spectrum(energy_row, 0);
    for (int p = 0; p <= row; p++){
        for ( int q = 0; q < energy_row; q++ ){

            double peak = spectral_energy[p];
            double area = spectral_intensity[p];
            double amplitude = area / ( width * sqrt(2*M_PI) );

            //define a Gaussian function for the intensity peaks
            solar_spectrum[q] = solar_spectrum[q] + amplitude
            * exp( -(input_energy[q] - peak)*(input_energy[q] - peak) / (2 * width*width) );

        }
    }

    //outputs total intensity spectrum to a file
    fstream spectrum_out("../Results/Total_Intensity_CHIANTI.dat", fstream::out);
    for (int l=0; l<energy_row; l++){

        spectrum_out << scientific << input_energy[l] << " " << solar_spectrum[l] << endl;
    }
    spectrum_out.close();

    return 0;
}
