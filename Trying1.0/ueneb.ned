//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//
//simple Txc1
//{
//    gates:
//        input in;
//        output out;
//}

//
// Two instances (tic and toc) of Txc1 connected both ways.
// Tic and toc will pass messages to one another.
//
//network Tictoc1
//{
//    @display("bgb=149,184");
//    submodules:
//        tic: Txc1;
//        toc: Txc1 {
//            @display("p=103,29");
//        }
//    connections:
//        tic.out --> {  delay = 100ms; } --> toc.in;
//        tic.in <-- {  delay = 100ms; } <-- toc.out;
//}

// Define the network


network MyNetwork {
    // Parameters for UEs
    parameters:
        int numUEs = 5;
        int numeNBs = 2;

    // Submodules
    submodules:
        // Define eNBs
        eNB1: eNB {
            // Define parameters for eNBs
            @display("p=100,100;i=device/antennatower");
        }

        eNB2: eNB {
            // Define parameters for eNBs
            @display("p=400,400;i=device/antennatower");
        }

         Define UEs
        ue[1..numUEs]: UE {
            // Define parameters for UEs
            @display("p=100,200;i=device/mobile");
        }

//         ue1: UE {
//             // Define parameters for UE1
//             @display("p=100,200;i=device/mobile");
//         }
//         
//         ue2: UE {
//             // Define parameters for UE2
//             @display("p=150,200;i=device/mobile");
//         }
//         ue3: UE {
//             // Define parameters for UE2
//             @display("p=200,200;i=device/mobile");
//         }
//         ue4: UE {
//             // Define parameters for UE2
//             @display("p=250,200;i=device/mobile");
//         }
//         ue5: UE {
//             // Define parameters for UE2
//             @display("p=300,200;i=device/mobile");
//         }

    // Connections
    connections allowunconnected:
        // Connect UEs to eNBs
        for i=1..numUEs, for j=1..numeNBs {
            ue[i].out++ --> eNB(j).in++;
            eNB(j).out++ --> ue[i].in++;
//             ue{i}.out++ --> eNB{j}.in++;
//            eNB{j}.out++ --> ue{i}.in++;
        }
}
