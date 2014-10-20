Solar Plasma Spectrum Line Model
===============

Initial release of solar plasma spectrum line model.

This program is designed to simulate x-ray emissions from the solar plasma spectrum, also known as the coronal spectrum, by using the CHIANTI database to generate a model spectrum from 0.01 to 10.00 keV. As this model excludes x-ray emissions via solar blackbody radiation, the model becomes significantly inaccurate at lower energies. For physically accurate solar spectrum results, please use at energies greater than ~100 eV.

Note: to use in conjunction with other Chandra-related models, be sure to set the line width to 0.05 keV as this is the approximate resolution of Chandra.
