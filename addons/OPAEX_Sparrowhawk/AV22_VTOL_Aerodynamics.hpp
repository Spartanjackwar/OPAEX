//===============================================================================================
//Aerodynamics
//===============================================================================================
angleOfIndicence = "0*3.1415/180"; //The real AoI is -10 degrees, which is bad in Arma.
landingAoa = "10*3.1415/180";

stallSpeed = 40; //Stall speed and landingAoA are AI suggestions.
stallWarningTreshold = 0.1; //Percent of airspeed to begin warning.

envelope[] = {0, 0.01, 0.2, 4, 6, 7.6, 8.4, 9.2, 9.4, 9.6, 9.7, 9.8, 8, 1};

airBrake = 1;
flaps = 0;
tailHook = 0;
flapsFrictionCoef = 0;

aileronSensitivity = 0.5;
aileronCoef[] = {0.6, 0.8, 1, 1.1, 1.2, 1.2, 0.4};
aileronControlsSensitivityCoef = 2;
VTOLRollInfluence = 8;

elevatorSensitivity = 0.9;
elevatorCoef[] = {0.2, 0.39, 0.51, 0.6, 0.68, 0.75, 0.8, 0.85, 0.9, 0.74, 0.3};
elevatorControlsSensitivityCoef = 4;
VTOLPitchInfluence = 8;

rudderInfluence = 0.866;
rudderCoef[] = {0.2, 0.5, 1, 1.5, 1.8, 2.1, 2.4, 2.5, 2.6, 2.7, 2.7, 0.8, 0.4};
rudderControlsSensitivityCoef = 2;
VTOLYawInfluence = 12;

draconicForceXCoef = 14;
draconicForceYCoef = 1;
draconicForceZCoef = 1;
draconicTorqueXCoef[] = {14, 12, 11.2, 10.6, 9.9, 9.6, 9.7, 10.5, 11, 11.5, 12};
draconicTorqueYCoef[] = {0.5, 1, 2, 2.3, 3, 2.6, 2.4, 2.2, 2, 1.9, 1.8};

//Taken from the A-164 wipeout.
/*
Note, these air frictions are a polynomial system!
The variable component is the object's speed in a given component.
You can view this as a system of 3 equations; Think of these frictions as a matrix.

airFrictionCoefs2^2 * x + airFrictionCoefs1 * x + airFrictionCoefs0 = x-friction
The axes are in model space X, Y, Z.
 */
/*
airFrictionCoefs2[] = {0.001, 0.006, 7e-005};
airFrictionCoefs1[] = {0.1, 0.6, 0.0067};
airFrictionCoefs0[] = {0, 0, 0};
*/