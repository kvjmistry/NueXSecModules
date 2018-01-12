#ifndef SELECTION_FUNCTIONS_DATA_h
#define SELECTION_FUNCTIONS_DATA_h

#include "../xsecAna/TpcObjectContainer.h"
#include "../xsecAna/ParticleContainer.h"

#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TEfficiency.h"
#include "TCanvas.h"
#include "TH1.h"
#include "TH2.h"
#include "TLegend.h"
#include "THStack.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TPad.h"
#include "TMarker.h"

#include <iostream>
#include <vector>

#include "../xsecAna/LinkDef.h"




class selection_functions_data {

public:

selection_functions_data()=default;

void FillPostCutVectorData(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                           std::vector<std::pair<int, std::string> > * passed_tpco,
                           std::vector<std::tuple<int, int, double, double, double, std::string, std::string, int, int> > * post_cuts_v);
//***************************************************************************
//***************************************************************************
std::vector<int> TabulateOriginsData(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                     std::vector<std::pair<int, std::string> > * passed_tpco);
//***************************************************************************
//***************************************************************************
void PrintInfoData(std::vector<int> * counter_v, std::string cut_name);
//***************************************************************************
//***************************************************************************
std::pair<std::string, int> TPCO_Classifier_Data(xsecAna::TPCObjectContainer tpc_obj);
//***************************************************************************
//***************************************************************************
void PostCutsdEdxData(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                      std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                      TH1D * h_dedx_cuts_data);
//***************************************************************************
//***************************************************************************
void PostCutOpenAngleData(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                          std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                          TH1D * h_leading_shower_open_angle_data);
//***************************************************************************
//***************************************************************************
void PostCutTrkVtxData(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                       std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                       TH1D * h_trk_vtx_dist_data);
//***************************************************************************
//***************************************************************************
void TopologyPlots1Data(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                        std::vector<std::pair<int, std::string> > * passed_tpco,
                        TH2D * h_pfp_track_shower_data,
                        TH1D * h_pfp_track_data,
                        TH1D * h_pfp_shower_data
                        );
//***************************************************************************
//***************************************************************************
void TopologyPlots2Data(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                        std::vector<std::pair<int, std::string> > * passed_tpco,
                        TH2D * h_pfp_track_shower_data,
                        TH1D * h_pfp_track_data,
                        TH1D * h_pfp_shower_data
                        );
//***************************************************************************
//***************************************************************************
void PostCutsVtxFlashData(std::vector< double > largest_flash_v, std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                          std::vector<std::pair<int, std::string> > * passed_tpco, TH1D * h_vtx_flash_data);
//***************************************************************************
//***************************************************************************
void PostCutsShwrVtxData(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                         std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                         TH1D * h_shwr_vtx_dist_data);
//***************************************************************************
//***************************************************************************
void TopologyEfficiencyData(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                            std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                            std::vector<int> * no_track_data, std::vector<int> * has_track_data);
//***************************************************************************
//***************************************************************************
void dEdxVsOpenAngleData(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                         std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                         TH2D * h_dedx_open_angle_data);
//***************************************************************************
//***************************************************************************
void ShowerLengthvsHitsData(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                            std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                            TH2D * h_shwr_len_hits_data);
//***************************************************************************
//***************************************************************************
void SecondaryShowersDistData(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                              std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                              TH1D * h_second_shwr_dist_data);
//***************************************************************************
//***************************************************************************
void HitLengthRatioData(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                        std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                        TH1D * h_hit_length_ratio_data);
//***************************************************************************
//***************************************************************************
int MapFailureCutToStringData(const std::string failure_cut);
//***************************************************************************
//***************************************************************************
void FailureReasonData(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                       std::vector<std::pair<int, std::string> > * passed_tpco,
                       TH1D * h_failure_reason_data);
//***************************************************************************
//***************************************************************************


};


#endif
