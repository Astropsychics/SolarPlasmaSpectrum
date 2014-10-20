Solar Plasma Spectrum Line Model
===============

Initial release of solar plasma spectrum line model.

This program is designed to simulate x-ray emissions from the solar plasma spectrum, also known as the coronal spectrum, by using the CHIANTI database to generate a spectrum from 0.01 to 10.00 keV. Please note that this model is different than the total solar spectrum as it excludes x-ray emissions via solar blackbody radiation, which is significant at low energies. Therefore, please include blackbody emissions when attempting to model total solar spectrum at energies lower than ~100 eV. At energies greater than ~100 eV, this model is an accurate simulation of total solar x-ray emissions. 

Note: to use in conjunction with other Chandra-related models, be sure to set the line width to 0.05 keV as this is the approximate resolution of Chandra.
