xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 280;
 0.00000;22.51859;24.42674;,
 0.00000;26.18292;25.34532;,
 18.42589;24.16153;24.15772;,
 17.97952;22.51859;23.50819;,
 -17.97952;22.51859;23.50819;,
 -18.42589;24.16153;24.15772;,
 -28.73762;22.51859;-0.98051;,
 -29.36889;25.68678;-0.98051;,
 -17.97952;22.51859;-24.98694;,
 -18.42589;24.22539;-25.72350;,
 0.00000;22.51859;-26.02862;,
 0.00000;26.32534;-27.07041;,
 17.97952;22.51859;-24.98694;,
 18.42589;24.22539;-25.72350;,
 28.73762;22.51859;-0.98051;,
 29.36889;25.68678;-0.98051;,
 0.00000;27.70075;27.56277;,
 19.50353;24.84207;25.72568;,
 -19.50353;24.84207;25.72568;,
 -30.89289;26.99909;-0.98051;,
 -19.50353;24.93234;-27.50185;,
 0.00000;27.90212;-29.58539;,
 19.50353;24.93234;-27.50185;,
 30.89289;26.99909;-0.98051;,
 0.00000;26.18292;29.78034;,
 20.58116;24.16153;27.29376;,
 -20.58117;24.16153;27.29376;,
 -32.41690;25.68678;-0.98051;,
 -20.58117;24.22539;-29.28018;,
 0.00000;26.32534;-32.10023;,
 20.58117;24.22539;-29.28018;,
 32.41690;25.68678;-0.98051;,
 0.00000;22.51859;30.69848;,
 21.02754;22.51859;27.94318;,
 -21.02754;22.51859;27.94318;,
 -33.04817;22.51859;-0.98051;,
 -21.02754;22.51859;-30.01685;,
 0.00000;22.51859;-33.14215;,
 21.02754;22.51859;-30.01685;,
 33.04816;22.51859;-0.98051;,
 0.00000;18.85427;29.78034;,
 20.58116;20.87566;27.29376;,
 -20.58117;20.87566;27.29376;,
 -32.41690;19.35041;-0.98051;,
 -20.58117;20.81180;-29.28018;,
 0.00000;18.71187;-32.10023;,
 20.58117;20.81180;-29.28018;,
 32.41690;19.35041;-0.98051;,
 0.00000;17.33644;27.56277;,
 19.50353;20.19514;25.72568;,
 -19.50353;20.19514;25.72568;,
 -30.89289;18.03810;-0.98051;,
 -19.50353;20.10484;-27.50185;,
 0.00000;17.13506;-29.58539;,
 19.50353;20.10484;-27.50185;,
 30.89289;18.03810;-0.98051;,
 0.00000;18.85427;25.34532;,
 18.42589;20.87566;24.15772;,
 -18.42589;20.87566;24.15772;,
 -29.36889;19.35041;-0.98051;,
 -18.42589;20.81180;-25.72350;,
 0.00000;18.71187;-27.07041;,
 18.42589;20.81180;-25.72350;,
 29.36889;19.35041;-0.98051;,
 9.84202;26.71592;-25.58520;,
 -10.15798;26.71592;-25.58520;,
 -10.15798;23.06463;-24.07278;,
 9.84202;23.06463;-24.07278;,
 -10.15798;19.41334;-25.58520;,
 9.84202;19.41334;-25.58520;,
 -10.15798;17.90092;-29.23650;,
 9.84202;17.90092;-29.23650;,
 -10.15798;19.41334;-32.88779;,
 9.84202;19.41334;-32.88779;,
 -10.15798;23.06463;-34.40021;,
 9.84202;23.06463;-34.40021;,
 -10.15798;26.71592;-32.88779;,
 9.84202;26.71592;-32.88779;,
 -10.15798;28.22834;-29.23650;,
 9.84202;28.22834;-29.23650;,
 9.84202;23.06463;-29.23650;,
 -10.15798;23.06463;-29.23650;,
 -7.12982;-11.84500;7.48360;,
 -4.39507;-14.98406;10.65437;,
 -4.47574;-8.07360;13.51697;,
 -7.17348;-8.10507;9.03283;,
 -4.55641;-1.16312;10.65437;,
 -7.21714;-4.36516;7.48360;,
 -4.58983;1.69927;3.74343;,
 -7.23523;-2.81603;3.74343;,
 -4.55641;-1.16312;-3.16750;,
 -7.21714;-4.36516;0.00326;,
 -4.47574;-8.07360;-6.03010;,
 -7.17348;-8.10507;-1.54597;,
 -4.39507;-14.98406;-3.16750;,
 -7.12982;-11.84500;0.00326;,
 -4.36166;-17.84647;3.74343;,
 -7.11174;-13.39413;3.74343;,
 -0.33288;-17.05542;12.77301;,
 -0.43828;-8.02645;16.51318;,
 -0.54369;1.00250;12.77301;,
 -0.58734;4.74241;3.74343;,
 -0.54369;1.00250;-5.28614;,
 -0.43828;-8.02645;-9.02631;,
 -0.33288;-17.05542;-5.28614;,
 -0.28922;-20.79533;3.74343;,
 4.43831;-17.74374;13.51697;,
 4.32422;-7.97087;17.56531;,
 4.21014;1.80200;13.51697;,
 4.16288;5.85006;3.74343;,
 4.21014;1.80200;-6.03010;,
 4.32422;-7.97087;-10.07844;,
 4.43831;-17.74374;-6.03011;,
 4.48556;-21.79178;3.74343;,
 9.19213;-16.94422;12.77301;,
 9.08673;-7.91527;16.51318;,
 8.98132;1.11370;12.77301;,
 8.93767;4.85361;3.74343;,
 8.98132;1.11370;-5.28614;,
 9.08673;-7.91527;-9.02631;,
 9.19213;-16.94422;-5.28614;,
 9.23579;-20.68415;3.74343;,
 13.20486;-14.77860;10.65437;,
 13.12418;-7.86814;13.51697;,
 13.04351;-0.95766;10.65437;,
 13.01010;1.90473;3.74343;,
 13.04351;-0.95766;-3.16750;,
 13.12418;-7.86814;-6.03010;,
 13.20486;-14.77860;-3.16750;,
 13.23827;-17.64101;3.74343;,
 15.86558;-11.57656;7.48360;,
 15.82193;-7.83663;9.03283;,
 15.77827;-4.09672;7.48360;,
 15.76019;-2.54759;3.74343;,
 15.77827;-4.09672;0.00326;,
 15.82193;-7.83663;-1.54597;,
 15.86558;-11.57656;0.00326;,
 15.88367;-13.12569;3.74343;,
 -8.12081;-8.11613;3.74343;,
 16.76925;-7.82559;3.74343;,
 -16.33794;-12.08182;7.71224;,
 -13.43601;-15.41275;11.07682;,
 -13.52161;-8.07987;14.11441;,
 -16.38427;-8.11329;9.35617;,
 -13.60722;-0.74698;11.07682;,
 -16.43059;-4.14477;7.71224;,
 -13.64267;2.29040;3.74343;,
 -16.44978;-2.50094;3.74343;,
 -13.60722;-0.74698;-3.58996;,
 -16.43059;-4.14477;-0.22537;,
 -13.52161;-8.07987;-6.62755;,
 -16.38427;-8.11329;-1.86930;,
 -13.43601;-15.41275;-3.58996;,
 -16.33794;-12.08182;-0.22537;,
 -13.40055;-18.45015;3.74343;,
 -16.31875;-13.72565;3.74343;,
 -9.12551;-17.61072;13.32497;,
 -9.23735;-8.02984;17.29377;,
 -9.34920;1.55103;13.32497;,
 -9.39553;5.51956;3.74343;,
 -9.34920;1.55103;-5.83810;,
 -9.23735;-8.02984;-9.80690;,
 -9.12551;-17.61074;-5.83810;,
 -9.07918;-21.57927;3.74343;,
 -4.06267;-18.34112;14.11441;,
 -4.18372;-7.97087;18.41021;,
 -4.30478;2.39940;14.11441;,
 -4.35493;6.69492;3.74343;,
 -4.30478;2.39940;-6.62755;,
 -4.18372;-7.97087;-10.92335;,
 -4.06267;-18.34112;-6.62755;,
 -4.01252;-22.63664;3.74343;,
 0.98175;-17.49274;13.32497;,
 0.86991;-7.91186;17.29377;,
 0.75806;1.66902;13.32497;,
 0.71173;5.63755;3.74343;,
 0.75806;1.66902;-5.83810;,
 0.86991;-7.91186;-9.80690;,
 0.98175;-17.49275;-5.83810;,
 1.02808;-21.46128;3.74343;,
 5.23977;-15.19474;11.07682;,
 5.15417;-7.86185;14.11441;,
 5.06856;-0.52897;11.07682;,
 5.03311;2.50841;3.74343;,
 5.06856;-0.52897;-3.58996;,
 5.15417;-7.86185;-6.62755;,
 5.23977;-15.19474;-3.58996;,
 5.27523;-18.23212;3.74343;,
 8.06315;-11.79697;7.71224;,
 8.01682;-7.82843;9.35617;,
 7.97049;-3.85990;7.71224;,
 7.95130;-2.21607;3.74343;,
 7.97049;-3.85990;-0.22537;,
 8.01682;-7.82843;-1.86930;,
 8.06315;-11.79697;-0.22537;,
 8.08233;-13.44078;3.74343;,
 -17.38949;-8.12502;3.74343;,
 9.02205;-7.81670;3.74343;,
 21.52538;10.64888;24.64646;,
 21.52538;19.42972;24.64646;,
 -0.70109;19.42972;34.85535;,
 -0.70109;10.64888;34.85535;,
 -22.92757;19.42972;24.64646;,
 -22.92757;10.64888;24.64646;,
 -32.13408;19.42972;0.00000;,
 -32.13408;10.64888;0.00000;,
 -22.92757;19.42972;-24.64645;,
 -22.92757;10.64888;-24.64645;,
 -0.70109;19.42972;-34.85535;,
 -0.70109;10.64888;-34.85535;,
 21.52538;19.42972;-24.64645;,
 21.52538;10.64888;-24.64645;,
 30.73189;19.42972;0.00000;,
 30.73189;10.64888;0.00000;,
 -0.70109;10.64888;34.85535;,
 -0.70109;10.64888;0.00000;,
 21.52538;10.64888;24.64646;,
 -22.92757;10.64888;24.64646;,
 -32.13408;10.64888;0.00000;,
 -22.92757;10.64888;-24.64645;,
 -0.70109;10.64888;-34.85535;,
 21.52538;10.64888;-24.64645;,
 30.73189;10.64888;0.00000;,
 21.52538;19.42972;24.64646;,
 -0.70109;19.42972;0.00000;,
 -0.70109;19.42972;34.85535;,
 -22.92757;19.42972;24.64646;,
 -32.13408;19.42972;0.00000;,
 -22.92757;19.42972;-24.64645;,
 -0.70109;19.42972;-34.85535;,
 21.52538;19.42972;-24.64645;,
 30.73189;19.42972;0.00000;,
 -7.56778;-11.57196;-18.79748;,
 -7.56778;0.51399;-15.52351;,
 7.10078;0.51399;-15.52351;,
 7.10078;-11.57196;-18.79748;,
 -7.56778;13.20375;-16.89715;,
 -7.56778;13.20375;21.70425;,
 7.10078;13.20375;21.70425;,
 7.10078;13.20375;-16.89715;,
 -7.56778;3.11113;21.70425;,
 -7.56778;-11.57196;21.70425;,
 7.10078;-11.57196;21.70425;,
 7.10078;3.11113;21.70425;,
 -7.56778;-28.22834;21.70425;,
 -7.56778;-28.22834;-27.94950;,
 7.10078;-28.22834;-27.94950;,
 7.10078;-28.22834;21.70425;,
 7.10078;-11.57196;-18.79748;,
 7.10078;0.51399;-15.52351;,
 7.10078;3.11113;21.70425;,
 7.10078;-11.57196;21.70425;,
 -7.56778;-11.57196;21.70425;,
 -7.56778;3.11113;21.70425;,
 -7.56778;0.51399;-15.52351;,
 -7.56778;-11.57196;-18.79748;,
 -7.56778;-20.91528;-27.42315;,
 7.10078;-20.91528;-27.42315;,
 7.10078;-20.91528;-27.42315;,
 7.10078;-20.91528;21.70425;,
 -7.56778;-20.91528;21.70425;,
 7.10078;-20.91528;21.70425;,
 -7.56778;-20.91528;21.70425;,
 -7.56778;-20.91528;-27.42315;,
 -7.56778;-28.22834;-27.94950;,
 7.10078;-28.22834;-27.94950;,
 7.10078;-28.22834;-27.94950;,
 7.10078;-28.22834;21.70425;,
 -7.56778;-28.22834;21.70425;,
 7.10078;-28.22834;21.70425;,
 -7.56778;-28.22834;21.70425;,
 -7.56778;-28.22834;-27.94950;,
 -7.56778;13.20375;21.70425;,
 7.10078;13.20375;21.70425;,
 7.10078;13.20375;-16.89715;,
 7.10078;13.20375;21.70425;,
 -7.56778;13.20375;-16.89715;,
 7.10078;13.20375;-16.89715;,
 -7.56778;13.20375;21.70425;,
 -7.56778;13.20375;-16.89715;;
 
 258;
 4;0,1,2,3;,
 4;4,5,1,0;,
 4;6,7,5,4;,
 4;8,9,7,6;,
 4;10,11,9,8;,
 4;12,13,11,10;,
 4;14,15,13,12;,
 4;3,2,15,14;,
 4;1,16,17,2;,
 4;5,18,16,1;,
 4;7,19,18,5;,
 4;9,20,19,7;,
 4;11,21,20,9;,
 4;13,22,21,11;,
 4;15,23,22,13;,
 4;2,17,23,15;,
 4;16,24,25,17;,
 4;18,26,24,16;,
 4;19,27,26,18;,
 4;20,28,27,19;,
 4;21,29,28,20;,
 4;22,30,29,21;,
 4;23,31,30,22;,
 4;17,25,31,23;,
 4;24,32,33,25;,
 4;26,34,32,24;,
 4;27,35,34,26;,
 4;28,36,35,27;,
 4;29,37,36,28;,
 4;30,38,37,29;,
 4;31,39,38,30;,
 4;25,33,39,31;,
 4;32,40,41,33;,
 4;34,42,40,32;,
 4;35,43,42,34;,
 4;36,44,43,35;,
 4;37,45,44,36;,
 4;38,46,45,37;,
 4;39,47,46,38;,
 4;33,41,47,39;,
 4;40,48,49,41;,
 4;42,50,48,40;,
 4;43,51,50,42;,
 4;44,52,51,43;,
 4;45,53,52,44;,
 4;46,54,53,45;,
 4;47,55,54,46;,
 4;41,49,55,47;,
 4;48,56,57,49;,
 4;50,58,56,48;,
 4;51,59,58,50;,
 4;52,60,59,51;,
 4;53,61,60,52;,
 4;54,62,61,53;,
 4;55,63,62,54;,
 4;49,57,63,55;,
 4;56,0,3,57;,
 4;58,4,0,56;,
 4;59,6,4,58;,
 4;60,8,6,59;,
 4;61,10,8,60;,
 4;62,12,10,61;,
 4;63,14,12,62;,
 4;57,3,14,63;,
 4;64,65,66,67;,
 4;67,66,68,69;,
 4;69,68,70,71;,
 4;71,70,72,73;,
 4;73,72,74,75;,
 4;75,74,76,77;,
 4;77,76,78,79;,
 4;79,78,65,64;,
 3;67,80,64;,
 3;69,80,67;,
 3;71,80,69;,
 3;73,80,71;,
 3;75,80,73;,
 3;77,80,75;,
 3;79,80,77;,
 3;64,80,79;,
 3;65,81,66;,
 3;66,81,68;,
 3;68,81,70;,
 3;70,81,72;,
 3;72,81,74;,
 3;74,81,76;,
 3;76,81,78;,
 3;78,81,65;,
 4;82,83,84,85;,
 4;85,84,86,87;,
 4;87,86,88,89;,
 4;89,88,90,91;,
 4;91,90,92,93;,
 4;93,92,94,95;,
 4;95,94,96,97;,
 4;97,96,83,82;,
 4;83,98,99,84;,
 4;84,99,100,86;,
 4;86,100,101,88;,
 4;88,101,102,90;,
 4;90,102,103,92;,
 4;92,103,104,94;,
 4;94,104,105,96;,
 4;96,105,98,83;,
 4;98,106,107,99;,
 4;99,107,108,100;,
 4;100,108,109,101;,
 4;101,109,110,102;,
 4;102,110,111,103;,
 4;103,111,112,104;,
 4;104,112,113,105;,
 4;105,113,106,98;,
 4;106,114,115,107;,
 4;107,115,116,108;,
 4;108,116,117,109;,
 4;109,117,118,110;,
 4;110,118,119,111;,
 4;111,119,120,112;,
 4;112,120,121,113;,
 4;113,121,114,106;,
 4;114,122,123,115;,
 4;115,123,124,116;,
 4;116,124,125,117;,
 4;117,125,126,118;,
 4;118,126,127,119;,
 4;119,127,128,120;,
 4;120,128,129,121;,
 4;121,129,122,114;,
 4;122,130,131,123;,
 4;123,131,132,124;,
 4;124,132,133,125;,
 4;125,133,134,126;,
 4;126,134,135,127;,
 4;127,135,136,128;,
 4;128,136,137,129;,
 4;129,137,130,122;,
 3;85,138,82;,
 3;87,138,85;,
 3;89,138,87;,
 3;91,138,89;,
 3;93,138,91;,
 3;95,138,93;,
 3;97,138,95;,
 3;82,138,97;,
 3;130,139,131;,
 3;131,139,132;,
 3;132,139,133;,
 3;133,139,134;,
 3;134,139,135;,
 3;135,139,136;,
 3;136,139,137;,
 3;137,139,130;,
 4;140,141,142,143;,
 4;143,142,144,145;,
 4;145,144,146,147;,
 4;147,146,148,149;,
 4;149,148,150,151;,
 4;151,150,152,153;,
 4;153,152,154,155;,
 4;155,154,141,140;,
 4;141,156,157,142;,
 4;142,157,158,144;,
 4;144,158,159,146;,
 4;146,159,160,148;,
 4;148,160,161,150;,
 4;150,161,162,152;,
 4;152,162,163,154;,
 4;154,163,156,141;,
 4;156,164,165,157;,
 4;157,165,166,158;,
 4;158,166,167,159;,
 4;159,167,168,160;,
 4;160,168,169,161;,
 4;161,169,170,162;,
 4;162,170,171,163;,
 4;163,171,164,156;,
 4;164,172,173,165;,
 4;165,173,174,166;,
 4;166,174,175,167;,
 4;167,175,176,168;,
 4;168,176,177,169;,
 4;169,177,178,170;,
 4;170,178,179,171;,
 4;171,179,172,164;,
 4;172,180,181,173;,
 4;173,181,182,174;,
 4;174,182,183,175;,
 4;175,183,184,176;,
 4;176,184,185,177;,
 4;177,185,186,178;,
 4;178,186,187,179;,
 4;179,187,180,172;,
 4;180,188,189,181;,
 4;181,189,190,182;,
 4;182,190,191,183;,
 4;183,191,192,184;,
 4;184,192,193,185;,
 4;185,193,194,186;,
 4;186,194,195,187;,
 4;187,195,188,180;,
 3;143,196,140;,
 3;145,196,143;,
 3;147,196,145;,
 3;149,196,147;,
 3;151,196,149;,
 3;153,196,151;,
 3;155,196,153;,
 3;140,196,155;,
 3;188,197,189;,
 3;189,197,190;,
 3;190,197,191;,
 3;191,197,192;,
 3;192,197,193;,
 3;193,197,194;,
 3;194,197,195;,
 3;195,197,188;,
 4;198,199,200,201;,
 4;201,200,202,203;,
 4;203,202,204,205;,
 4;205,204,206,207;,
 4;207,206,208,209;,
 4;209,208,210,211;,
 4;211,210,212,213;,
 4;213,212,199,198;,
 3;214,215,216;,
 3;217,215,214;,
 3;218,215,217;,
 3;219,215,218;,
 3;220,215,219;,
 3;221,215,220;,
 3;222,215,221;,
 3;216,215,222;,
 3;223,224,225;,
 3;225,224,226;,
 3;226,224,227;,
 3;227,224,228;,
 3;228,224,229;,
 3;229,224,230;,
 3;230,224,231;,
 3;231,224,223;,
 4;232,233,234,235;,
 4;236,237,238,239;,
 4;240,241,242,243;,
 4;244,245,246,247;,
 4;248,249,250,251;,
 4;252,253,254,255;,
 4;256,232,235,257;,
 4;258,248,251,259;,
 4;241,260,261,242;,
 4;262,252,255,263;,
 4;264,256,257,265;,
 4;266,258,259,267;,
 4;260,268,269,261;,
 4;270,262,263,271;,
 4;272,240,243,273;,
 4;249,274,275,250;,
 4;233,276,277,234;,
 4;253,278,279,254;;
 
 MeshMaterialList {
  1;
  258;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\MATERIAL\\arms_02.png";
   }
  }
 }
 MeshNormals {
  219;
  -0.036086;-0.000001;-0.999349;,
  0.000000;-0.000001;-1.000000;,
  0.036086;-0.000001;-0.999349;,
  0.999995;-0.000001;0.003251;,
  0.917813;-0.000001;0.397012;,
  0.000000;-0.000001;1.000000;,
  -0.040982;-0.000001;0.999160;,
  -0.999995;-0.000001;0.003251;,
  -0.188711;0.761164;-0.620498;,
  0.000000;0.625137;-0.780515;,
  0.188711;0.761164;-0.620498;,
  0.787187;0.616708;0.002738;,
  0.512748;0.762185;0.395174;,
  0.000000;0.649624;0.760256;,
  -0.187443;0.774581;0.604060;,
  -0.787187;0.616708;0.002738;,
  0.049672;0.998745;0.006403;,
  0.000000;0.999295;-0.037548;,
  -0.049672;0.998745;0.006403;,
  0.539402;0.842046;0.002080;,
  -0.052721;0.998595;-0.005295;,
  0.000000;0.999370;0.035482;,
  0.052721;0.998595;-0.005295;,
  -0.539402;0.842046;0.002080;,
  0.472219;0.665942;0.577521;,
  0.000000;0.656717;0.754137;,
  -0.472219;0.665942;0.577521;,
  -0.772361;0.635183;0.000887;,
  -0.476796;0.675262;-0.562749;,
  0.000000;0.679292;-0.733868;,
  0.476797;0.675262;-0.562749;,
  0.772362;0.635183;0.000887;,
  0.611463;-0.000001;0.791273;,
  0.000000;-0.000001;1.000000;,
  -0.611463;-0.000001;0.791273;,
  -1.000000;-0.000001;0.000624;,
  -0.620883;-0.000001;-0.783903;,
  0.000000;-0.000001;-1.000000;,
  0.620883;-0.000001;-0.783903;,
  1.000000;-0.000001;0.000624;,
  0.472217;-0.665945;0.577519;,
  0.000000;-0.656720;0.754135;,
  -0.472217;-0.665945;0.577519;,
  -0.772360;-0.635184;0.000887;,
  -0.476796;-0.675261;-0.562750;,
  0.000000;-0.679290;-0.733870;,
  0.476796;-0.675261;-0.562750;,
  0.772361;-0.635184;0.000887;,
  0.049672;-0.998745;0.006403;,
  0.000000;-0.999295;-0.037548;,
  -0.049672;-0.998745;0.006403;,
  -0.493385;-0.869810;0.001046;,
  -0.262137;-0.962425;-0.070870;,
  0.000000;-0.999370;0.035482;,
  0.052721;-0.998595;-0.005295;,
  0.493386;-0.869810;0.001046;,
  -0.414282;-0.682962;-0.601609;,
  0.000000;-0.625140;-0.780513;,
  0.414282;-0.682962;-0.601609;,
  0.787186;-0.616709;0.002739;,
  0.411586;-0.694338;0.590332;,
  0.000000;-0.649622;0.760257;,
  -0.411586;-0.694338;0.590332;,
  -0.787186;-0.616709;0.002739;,
  0.000000;0.707107;0.707106;,
  0.000000;-0.000000;1.000000;,
  0.000000;-0.707107;0.707107;,
  0.000000;-1.000000;-0.000000;,
  0.000000;-0.707107;-0.707107;,
  0.000000;-0.000000;-1.000000;,
  0.000000;0.707107;-0.707106;,
  0.000000;1.000000;-0.000000;,
  1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  -0.933777;-0.258441;0.247524;,
  -0.936666;-0.010934;0.350052;,
  -0.939556;0.236573;0.247525;,
  -0.940753;0.339094;0.000000;,
  -0.939555;0.236573;-0.247525;,
  -0.936666;-0.010934;-0.350052;,
  -0.933777;-0.258441;-0.247525;,
  -0.932581;-0.360962;-0.000000;,
  -0.736898;-0.482304;0.473670;,
  -0.742427;-0.008667;0.669870;,
  -0.747956;0.464971;0.473670;,
  -0.750246;0.661159;-0.000000;,
  -0.747956;0.464971;-0.473670;,
  -0.742427;-0.008667;-0.669871;,
  -0.736898;-0.482304;-0.473670;,
  -0.734608;-0.678492;-0.000000;,
  -0.409696;-0.647447;0.642621;,
  -0.417197;-0.004870;0.908803;,
  -0.424698;0.637707;0.642620;,
  -0.427805;0.903871;-0.000000;,
  -0.424698;0.637707;-0.642621;,
  -0.417198;-0.004870;-0.908803;,
  -0.409696;-0.647447;-0.642621;,
  -0.406588;-0.913612;-0.000000;,
  0.008254;-0.707059;0.707106;,
  0.000000;0.000000;1.000000;,
  -0.008254;0.707059;0.707106;,
  -0.011674;0.999932;-0.000000;,
  -0.008254;0.707059;-0.707107;,
  -0.000000;0.000000;-1.000000;,
  0.008254;-0.707059;-0.707107;,
  0.011673;-0.999932;-0.000000;,
  0.424699;-0.637707;0.642621;,
  0.417198;0.004870;0.908803;,
  0.409696;0.647447;0.642621;,
  0.406588;0.913612;-0.000000;,
  0.409696;0.647447;-0.642621;,
  0.417198;0.004870;-0.908803;,
  0.424699;-0.637706;-0.642621;,
  0.427805;-0.903871;-0.000000;,
  0.747957;-0.464970;0.473670;,
  0.742427;0.008667;0.669871;,
  0.736898;0.482305;0.473670;,
  0.734607;0.678492;-0.000000;,
  0.736898;0.482305;-0.473670;,
  0.742427;0.008667;-0.669871;,
  0.747956;-0.464971;-0.473671;,
  0.750247;-0.661158;-0.000000;,
  0.939556;-0.236573;0.247524;,
  0.936667;0.010934;0.350052;,
  0.933777;0.258441;0.247524;,
  0.932581;0.360962;0.000000;,
  0.933777;0.258441;-0.247524;,
  0.936666;0.010934;-0.350052;,
  0.939556;-0.236573;-0.247525;,
  0.940753;-0.339093;-0.000000;,
  -0.999932;-0.011673;-0.000000;,
  0.999932;0.011672;-0.000000;,
  -0.933777;-0.258441;0.247524;,
  -0.936667;-0.010934;0.350051;,
  -0.939556;0.236573;0.247523;,
  -0.940753;0.339093;-0.000000;,
  -0.939556;0.236573;-0.247523;,
  -0.936667;-0.010934;-0.350051;,
  -0.933777;-0.258441;-0.247524;,
  -0.932581;-0.360962;-0.000000;,
  -0.736897;-0.482305;0.473671;,
  -0.742427;-0.008667;0.669871;,
  -0.747957;0.464971;0.473670;,
  -0.750247;0.661158;-0.000000;,
  -0.747957;0.464971;-0.473670;,
  -0.742427;-0.008667;-0.669871;,
  -0.736897;-0.482305;-0.473671;,
  -0.734607;-0.678493;0.000000;,
  -0.409696;-0.647447;0.642621;,
  -0.417197;-0.004870;0.908803;,
  -0.424698;0.637707;0.642621;,
  -0.427806;0.903871;-0.000000;,
  -0.424698;0.637707;-0.642621;,
  -0.417197;-0.004870;-0.908803;,
  -0.409696;-0.647447;-0.642621;,
  -0.406589;-0.913611;0.000000;,
  0.008254;-0.707058;0.707107;,
  -0.000000;-0.000000;1.000000;,
  -0.008254;0.707058;0.707107;,
  -0.011673;0.999932;-0.000000;,
  -0.008254;0.707058;-0.707107;,
  0.000000;0.000000;-1.000000;,
  0.008254;-0.707058;-0.707107;,
  0.011673;-0.999932;0.000000;,
  0.424698;-0.637707;0.642621;,
  0.417197;0.004870;0.908803;,
  0.409696;0.647447;0.642621;,
  0.406589;0.913611;-0.000000;,
  0.409696;0.647447;-0.642621;,
  0.417197;0.004870;-0.908803;,
  0.424699;-0.637707;-0.642621;,
  0.427806;-0.903871;0.000000;,
  0.747956;-0.464971;0.473670;,
  0.742427;0.008667;0.669871;,
  0.736898;0.482305;0.473670;,
  0.734608;0.678492;-0.000000;,
  0.736898;0.482305;-0.473670;,
  0.742427;0.008667;-0.669871;,
  0.747956;-0.464971;-0.473670;,
  0.750246;-0.661158;0.000000;,
  0.939556;-0.236573;0.247523;,
  0.936667;0.010935;0.350052;,
  0.933777;0.258442;0.247524;,
  0.932580;0.360963;-0.000000;,
  0.933777;0.258442;-0.247524;,
  0.936667;0.010935;-0.350052;,
  0.939556;-0.236573;-0.247523;,
  0.940752;-0.339094;-0.000000;,
  -0.999932;-0.011672;-0.000000;,
  0.999932;0.011673;-0.000000;,
  0.732466;0.000000;0.680804;,
  0.000000;0.000000;1.000000;,
  -0.732466;0.000000;0.680804;,
  -1.000000;0.000000;-0.000000;,
  -0.732466;0.000000;-0.680803;,
  0.000000;0.000000;-1.000000;,
  0.732466;0.000000;-0.680803;,
  1.000000;0.000000;-0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;0.483817;-0.875169;,
  0.000000;-0.000000;1.000000;,
  0.000000;0.397385;-0.917652;,
  0.000000;0.078277;-0.996932;,
  0.884390;0.277302;-0.375443;,
  0.920489;-0.000001;-0.390767;,
  0.038641;0.333114;0.942095;,
  0.040982;-0.000001;0.999160;,
  -0.881219;0.279560;0.381182;,
  -0.917813;-0.000001;0.397012;,
  -0.920489;-0.000001;-0.390767;,
  -0.884390;0.277302;-0.375443;,
  -0.493387;0.869810;0.001047;,
  0.493387;0.869809;0.001047;,
  0.539401;-0.842047;0.002081;,
  0.530590;-0.829502;0.174356;,
  -0.539401;-0.842047;0.002081;,
  0.000000;0.071788;-0.997420;,
  0.000000;-0.107619;-0.994192;;
  258;
  4;1,9,8,0;,
  4;2,10,9,1;,
  4;3,11,204,205;,
  4;4,12,11,3;,
  4;5,13,206,207;,
  4;6,14,13,5;,
  4;7,15,208,209;,
  4;210,211,15,7;,
  4;9,17,16,8;,
  4;10,18,17,9;,
  4;11,19,18,10;,
  4;12,20,19,11;,
  4;13,21,20,12;,
  4;14,22,21,13;,
  4;15,23,22,14;,
  4;8,16,23,15;,
  4;17,25,24,16;,
  4;18,26,25,17;,
  4;212,27,26,18;,
  4;20,28,27,212;,
  4;21,29,28,20;,
  4;22,30,29,21;,
  4;213,31,30,22;,
  4;16,24,31,213;,
  4;25,33,32,24;,
  4;26,34,33,25;,
  4;27,35,34,26;,
  4;28,36,35,27;,
  4;29,37,36,28;,
  4;30,38,37,29;,
  4;31,39,38,30;,
  4;24,32,39,31;,
  4;33,41,40,32;,
  4;34,42,41,33;,
  4;35,43,42,34;,
  4;36,44,43,35;,
  4;37,45,44,36;,
  4;38,46,45,37;,
  4;39,47,46,38;,
  4;32,40,47,39;,
  4;41,49,48,40;,
  4;42,50,49,41;,
  4;43,51,50,42;,
  4;44,52,51,43;,
  4;45,53,52,44;,
  4;46,54,53,45;,
  4;47,55,54,46;,
  4;40,48,55,47;,
  4;49,57,56,48;,
  4;50,58,57,49;,
  4;214,59,58,50;,
  4;215,60,59,214;,
  4;53,61,60,52;,
  4;54,62,61,53;,
  4;216,63,62,54;,
  4;48,56,63,216;,
  4;57,1,0,56;,
  4;58,2,1,57;,
  4;59,3,205,58;,
  4;60,4,3,59;,
  4;61,5,207,60;,
  4;62,6,5,61;,
  4;63,7,209,62;,
  4;56,210,7,63;,
  4;64,64,65,65;,
  4;65,65,66,66;,
  4;66,66,67,67;,
  4;67,67,68,68;,
  4;68,68,69,69;,
  4;69,69,70,70;,
  4;70,70,71,71;,
  4;71,71,64,64;,
  3;72,72,72;,
  3;72,72,72;,
  3;72,72,72;,
  3;72,72,72;,
  3;72,72,72;,
  3;72,72,72;,
  3;72,72,72;,
  3;72,72,72;,
  3;73,73,73;,
  3;73,73,73;,
  3;73,73,73;,
  3;73,73,73;,
  3;73,73,73;,
  3;73,73,73;,
  3;73,73,73;,
  3;73,73,73;,
  4;74,82,83,75;,
  4;75,83,84,76;,
  4;76,84,85,77;,
  4;77,85,86,78;,
  4;78,86,87,79;,
  4;79,87,88,80;,
  4;80,88,89,81;,
  4;81,89,82,74;,
  4;82,90,91,83;,
  4;83,91,92,84;,
  4;84,92,93,85;,
  4;85,93,94,86;,
  4;86,94,95,87;,
  4;87,95,96,88;,
  4;88,96,97,89;,
  4;89,97,90,82;,
  4;90,98,99,91;,
  4;91,99,100,92;,
  4;92,100,101,93;,
  4;93,101,102,94;,
  4;94,102,103,95;,
  4;95,103,104,96;,
  4;96,104,105,97;,
  4;97,105,98,90;,
  4;98,106,107,99;,
  4;99,107,108,100;,
  4;100,108,109,101;,
  4;101,109,110,102;,
  4;102,110,111,103;,
  4;103,111,112,104;,
  4;104,112,113,105;,
  4;105,113,106,98;,
  4;106,114,115,107;,
  4;107,115,116,108;,
  4;108,116,117,109;,
  4;109,117,118,110;,
  4;110,118,119,111;,
  4;111,119,120,112;,
  4;112,120,121,113;,
  4;113,121,114,106;,
  4;114,122,123,115;,
  4;115,123,124,116;,
  4;116,124,125,117;,
  4;117,125,126,118;,
  4;118,126,127,119;,
  4;119,127,128,120;,
  4;120,128,129,121;,
  4;121,129,122,114;,
  3;75,130,74;,
  3;76,130,75;,
  3;77,130,76;,
  3;78,130,77;,
  3;79,130,78;,
  3;80,130,79;,
  3;81,130,80;,
  3;74,130,81;,
  3;122,131,123;,
  3;123,131,124;,
  3;124,131,125;,
  3;125,131,126;,
  3;126,131,127;,
  3;127,131,128;,
  3;128,131,129;,
  3;129,131,122;,
  4;132,140,141,133;,
  4;133,141,142,134;,
  4;134,142,143,135;,
  4;135,143,144,136;,
  4;136,144,145,137;,
  4;137,145,146,138;,
  4;138,146,147,139;,
  4;139,147,140,132;,
  4;140,148,149,141;,
  4;141,149,150,142;,
  4;142,150,151,143;,
  4;143,151,152,144;,
  4;144,152,153,145;,
  4;145,153,154,146;,
  4;146,154,155,147;,
  4;147,155,148,140;,
  4;148,156,157,149;,
  4;149,157,158,150;,
  4;150,158,159,151;,
  4;151,159,160,152;,
  4;152,160,161,153;,
  4;153,161,162,154;,
  4;154,162,163,155;,
  4;155,163,156,148;,
  4;156,164,165,157;,
  4;157,165,166,158;,
  4;158,166,167,159;,
  4;159,167,168,160;,
  4;160,168,169,161;,
  4;161,169,170,162;,
  4;162,170,171,163;,
  4;163,171,164,156;,
  4;164,172,173,165;,
  4;165,173,174,166;,
  4;166,174,175,167;,
  4;167,175,176,168;,
  4;168,176,177,169;,
  4;169,177,178,170;,
  4;170,178,179,171;,
  4;171,179,172,164;,
  4;172,180,181,173;,
  4;173,181,182,174;,
  4;174,182,183,175;,
  4;175,183,184,176;,
  4;176,184,185,177;,
  4;177,185,186,178;,
  4;178,186,187,179;,
  4;179,187,180,172;,
  3;133,188,132;,
  3;134,188,133;,
  3;135,188,134;,
  3;136,188,135;,
  3;137,188,136;,
  3;138,188,137;,
  3;139,188,138;,
  3;132,188,139;,
  3;180,189,181;,
  3;181,189,182;,
  3;182,189,183;,
  3;183,189,184;,
  3;184,189,185;,
  3;185,189,186;,
  3;186,189,187;,
  3;187,189,180;,
  4;190,190,191,191;,
  4;191,191,192,192;,
  4;192,192,193,193;,
  4;193,193,194,194;,
  4;194,194,195,195;,
  4;195,195,196,196;,
  4;196,196,197,197;,
  4;197,197,190,190;,
  3;198,198,198;,
  3;198,198,198;,
  3;198,198,198;,
  3;198,198,198;,
  3;198,198,198;,
  3;198,198,198;,
  3;198,198,198;,
  3;198,198,198;,
  3;199,199,199;,
  3;199,199,199;,
  3;199,199,199;,
  3;199,199,199;,
  3;199,199,199;,
  3;199,199,199;,
  3;199,199,199;,
  3;199,199,199;,
  4;200,203,203,200;,
  4;199,199,199,199;,
  4;201,201,201,201;,
  4;198,198,198,198;,
  4;72,72,72,72;,
  4;73,73,73,73;,
  4;202,200,200,202;,
  4;72,72,72,72;,
  4;201,201,201,201;,
  4;73,73,73,73;,
  4;217,202,202,217;,
  4;72,72,72,72;,
  4;201,201,201,201;,
  4;73,73,73,73;,
  4;201,201,201,201;,
  4;72,72,72,72;,
  4;203,218,218,203;,
  4;73,73,73,73;;
 }
 MeshTextureCoords {
  280;
  0.087403;0.343915;,
  0.087403;0.335718;,
  0.123661;0.340239;,
  0.122783;0.343915;,
  0.052023;0.343915;,
  0.051145;0.340239;,
  0.030854;0.343915;,
  0.029611;0.336828;,
  0.052023;0.343915;,
  0.051145;0.340097;,
  0.087403;0.343915;,
  0.087403;0.335399;,
  0.122783;0.343915;,
  0.123661;0.340097;,
  0.143952;0.343915;,
  0.145194;0.336828;,
  0.087403;0.332322;,
  0.125781;0.338717;,
  0.049024;0.338717;,
  0.026612;0.333892;,
  0.049024;0.338515;,
  0.087403;0.331872;,
  0.125781;0.338515;,
  0.148193;0.333892;,
  0.087403;0.335718;,
  0.127902;0.340239;,
  0.046904;0.340239;,
  0.023614;0.336828;,
  0.046904;0.340097;,
  0.087403;0.335399;,
  0.127902;0.340097;,
  0.151192;0.336828;,
  0.087403;0.343915;,
  0.128781;0.343915;,
  0.046025;0.343915;,
  0.022371;0.343915;,
  0.046025;0.343915;,
  0.087403;0.343915;,
  0.128781;0.343915;,
  0.152434;0.343915;,
  0.087403;0.352112;,
  0.127902;0.347590;,
  0.046904;0.347590;,
  0.023614;0.351002;,
  0.046904;0.347733;,
  0.087403;0.352430;,
  0.127902;0.347733;,
  0.151192;0.351002;,
  0.087403;0.355507;,
  0.125781;0.349112;,
  0.049024;0.349112;,
  0.026612;0.353938;,
  0.049024;0.349314;,
  0.087403;0.355958;,
  0.125781;0.349314;,
  0.148193;0.353938;,
  0.087403;0.352112;,
  0.123661;0.347590;,
  0.051145;0.347590;,
  0.029611;0.351002;,
  0.051145;0.347733;,
  0.087403;0.352430;,
  0.123661;0.347733;,
  0.145194;0.351002;,
  0.125257;0.285158;,
  0.043971;0.285158;,
  0.043971;0.300060;,
  0.125257;0.300060;,
  0.043971;0.314962;,
  0.125257;0.314962;,
  0.043971;0.321134;,
  0.125257;0.321134;,
  0.043971;0.314962;,
  0.125257;0.314962;,
  0.043971;0.300060;,
  0.125257;0.300060;,
  0.043971;0.285158;,
  0.125257;0.285158;,
  0.043971;0.278986;,
  0.125257;0.278986;,
  0.125257;0.300060;,
  0.043971;0.300060;,
  0.977383;0.039813;,
  0.982304;0.044685;,
  0.986747;0.033959;,
  0.979788;0.034008;,
  0.982304;0.023233;,
  0.977383;0.028203;,
  0.971579;0.018791;,
  0.971579;0.025799;,
  0.960853;0.023233;,
  0.965774;0.028203;,
  0.956411;0.033959;,
  0.963370;0.034008;,
  0.960853;0.044685;,
  0.965774;0.039813;,
  0.971579;0.049127;,
  0.971579;0.042217;,
  0.985592;0.047899;,
  0.991397;0.033886;,
  0.985592;0.019872;,
  0.971579;0.014068;,
  0.957565;0.019872;,
  0.951761;0.033886;,
  0.957565;0.047899;,
  0.971579;0.053704;,
  0.986747;0.048968;,
  0.993030;0.033800;,
  0.986747;0.018631;,
  0.971579;0.012349;,
  0.956411;0.018631;,
  0.950128;0.033800;,
  0.956411;0.048968;,
  0.971579;0.055251;,
  0.985592;0.047727;,
  0.991397;0.033713;,
  0.985592;0.019700;,
  0.971579;0.013895;,
  0.957565;0.019700;,
  0.951761;0.033713;,
  0.957565;0.047727;,
  0.971579;0.053532;,
  0.982304;0.044366;,
  0.986747;0.033640;,
  0.982304;0.022915;,
  0.971579;0.018472;,
  0.960853;0.022915;,
  0.956411;0.033640;,
  0.960853;0.044366;,
  0.971579;0.048808;,
  0.977383;0.039396;,
  0.979788;0.033591;,
  0.977383;0.027787;,
  0.971579;0.025382;,
  0.965774;0.027787;,
  0.963370;0.033591;,
  0.965774;0.039396;,
  0.971579;0.041800;,
  0.971579;0.034025;,
  0.971579;0.033574;,
  0.977738;0.040180;,
  0.982960;0.045350;,
  0.987674;0.033969;,
  0.980290;0.034021;,
  0.982960;0.022588;,
  0.977738;0.027861;,
  0.971579;0.017873;,
  0.971579;0.025310;,
  0.960198;0.022588;,
  0.965419;0.027861;,
  0.955483;0.033969;,
  0.962868;0.034021;,
  0.960198;0.045350;,
  0.965419;0.040180;,
  0.971579;0.050064;,
  0.971579;0.042731;,
  0.986449;0.048761;,
  0.992609;0.033891;,
  0.986449;0.019021;,
  0.971579;0.012861;,
  0.956709;0.019021;,
  0.950549;0.033891;,
  0.956709;0.048761;,
  0.971579;0.054921;,
  0.987674;0.049895;,
  0.994341;0.033800;,
  0.987674;0.017704;,
  0.971579;0.011037;,
  0.955483;0.017704;,
  0.948817;0.033800;,
  0.955483;0.049895;,
  0.971579;0.056562;,
  0.986449;0.048578;,
  0.992609;0.033708;,
  0.986449;0.018838;,
  0.971579;0.012678;,
  0.956709;0.018838;,
  0.950549;0.033708;,
  0.956709;0.048578;,
  0.971579;0.054738;,
  0.982960;0.045012;,
  0.987674;0.033630;,
  0.982960;0.022249;,
  0.971579;0.017535;,
  0.960198;0.022249;,
  0.955483;0.033630;,
  0.960198;0.045012;,
  0.971579;0.049726;,
  0.977738;0.039738;,
  0.980290;0.033578;,
  0.977738;0.027419;,
  0.971579;0.024868;,
  0.965419;0.027419;,
  0.962868;0.033578;,
  0.965419;0.039738;,
  0.971579;0.042289;,
  0.971579;0.034039;,
  0.971579;0.033560;,
  0.259512;0.398130;,
  0.259512;0.379739;,
  0.224658;0.379739;,
  0.224658;0.398130;,
  0.189804;0.379739;,
  0.189804;0.398130;,
  0.175367;0.379739;,
  0.175367;0.398130;,
  0.189804;0.379739;,
  0.189804;0.398130;,
  0.224658;0.379739;,
  0.224658;0.398130;,
  0.259512;0.379739;,
  0.259512;0.398130;,
  0.273949;0.379739;,
  0.273949;0.398130;,
  0.222399;0.269831;,
  0.222399;0.315991;,
  0.255039;0.283351;,
  0.189758;0.283351;,
  0.176238;0.315991;,
  0.189758;0.348632;,
  0.222399;0.362152;,
  0.255039;0.348632;,
  0.268560;0.315991;,
  0.255039;0.283351;,
  0.222399;0.315991;,
  0.222399;0.269831;,
  0.189758;0.283351;,
  0.176238;0.315991;,
  0.189758;0.348632;,
  0.222399;0.362152;,
  0.255039;0.348632;,
  0.268560;0.315991;,
  0.296477;0.346114;,
  0.296477;0.308892;,
  0.326014;0.308892;,
  0.326014;0.346114;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.485580;0.304828;,
  0.485580;0.343872;,
  0.504490;0.343872;,
  0.504490;0.304828;,
  0.342482;0.431327;,
  0.461459;0.431554;,
  0.461503;0.408419;,
  0.342526;0.408192;,
  0.361920;0.350325;,
  0.369891;0.315062;,
  0.460524;0.307484;,
  0.460524;0.350325;,
  0.460524;0.350325;,
  0.460524;0.307484;,
  0.369891;0.315062;,
  0.361920;0.350325;,
  0.296477;0.374889;,
  0.326014;0.374889;,
  0.340920;0.377585;,
  0.460524;0.377585;,
  0.485580;0.368718;,
  0.504490;0.368718;,
  0.460524;0.377585;,
  0.340920;0.377585;,
  0.296477;0.397411;,
  0.326014;0.397411;,
  0.339639;0.398922;,
  0.460524;0.398922;,
  0.485580;0.388165;,
  0.504490;0.388165;,
  0.460524;0.398922;,
  0.339639;0.398922;,
  0.485580;0.277989;,
  0.504490;0.277989;,
  0.366546;0.278037;,
  0.460524;0.278037;,
  0.296477;0.269811;,
  0.326014;0.269811;,
  0.460524;0.278037;,
  0.366546;0.278037;;
 }
}
