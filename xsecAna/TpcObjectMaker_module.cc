////////////////////////////////////////////////////////////////////////
// Class:       TpcObjectMaker
// Module Type: producer
// File:        TpcObjectMaker_module.cc
//
// Generated at Wed Sep 13 16:45:37 2017 by Colton Hill using artmod
// from cetpkgsupport v1_12_02.
////////////////////////////////////////////////////////////////////////

#include "art/Framework/Core/EDProducer.h"
#include "art/Framework/Core/ModuleMacros.h"
#include "art/Framework/Principal/Event.h"
#include "art/Framework/Principal/Handle.h"
#include "art/Framework/Principal/Run.h"
#include "art/Framework/Principal/SubRun.h"
#include "fhiclcpp/ParameterSet.h"
#include "messagefacility/MessageLogger/MessageLogger.h"
#include "larsim/MCCheater/BackTracker.h"

#include <memory>
#include <fstream>

#include "AnaHelper.h"
#include "RecoTrueHelper.h"
#include "TpcObjectHelper.h"
#include "TPCObject.h"
#include "MCGhost.h"

namespace xsecAna {
class TpcObjectMaker;
}

class xsecAna::TpcObjectMaker : public art::EDProducer {
public:
explicit TpcObjectMaker(fhicl::ParameterSet const & p);
// The destructor generated by the compiler is fine for classes
// without bare pointers or other resource use.

//TpcObjectMaker();
//virtual ~TpcObjectMaker();

// Plugins should not be copied or assigned.
TpcObjectMaker(TpcObjectMaker const &) = delete;
TpcObjectMaker(TpcObjectMaker &&) = delete;
TpcObjectMaker & operator = (TpcObjectMaker const &) = delete;
TpcObjectMaker & operator = (TpcObjectMaker &&) = delete;

// Required functions.
void produce(art::Event & e) override;
//void reconfigure(fhicl::ParameterSet const &p) override;


private:

// Declare member data here.
std::string _pfp_producer;
std::string _hitfinderLabel;
std::string _geantModuleLabel;
std::string _spacepointLabel;
std::string _neutrino_flash_match_producer;
std::string _cosmic_flash_match_producer;
std::string _opflash_producer_beam;
std::string _potsum_producer;
std::string _potsum_instance;
std::string _particle_id_producer;

std::string _vertexLabel;
std::string _trackLabel;
std::string _showerLabel;

bool _use_genie_info;
int _minimumHitRequirement;

double _beam_spill_start;
double _beam_spill_end;

bool _debug;
bool _verbose;
bool isMC;
bool isData;
bool _cosmic_only;
bool _use_premade_ass;
std::string _mcpHitAssLabel;

int run;
int event;


};

xsecAna::TpcObjectMaker::TpcObjectMaker(fhicl::ParameterSet const & p)
// :
// Initialize member data here.
{
	// Call appropriate produces<>() functions here.

	if(_verbose) {std::cout << "[TpcObjectMaker] --- start setting fcl parameters --- " << std::endl; }

	_pfp_producer                   = p.get<std::string>("PFParticleProducer");
	_hitfinderLabel                 = p.get<std::string>("HitProducer");
	_geantModuleLabel               = p.get<std::string>("GeantModule");
	_spacepointLabel                = p.get<std::string>("SpacePointProducer");
	_neutrino_flash_match_producer  = p.get<std::string>("NeutrinoFlashMatchProducer");
	_cosmic_flash_match_producer    = p.get<std::string>("CosmicFlashMatchProducer");
	_opflash_producer_beam          = p.get<std::string>("OpFlashBeamProducer");
	_potsum_producer                = p.get<std::string>("POTSummaryProducer");
	_potsum_instance                = p.get<std::string>("POTSummaryInstance");
	_particle_id_producer           = p.get<std::string>("ParticleIDProducer");

	_vertexLabel                    =p.get<std::string>("VertexProducer");
	_trackLabel                     =p.get<std::string>("TrackProducer");
	_showerLabel                    =p.get<std::string>("ShowerProducer");

	_use_genie_info                 = p.get<bool>("UseGENIEInfo", "false");
	_minimumHitRequirement          = p.get<int>("MinimumHitRequirement", 3);

	_beam_spill_start               = p.get<double>("BeamSpillStart", 3.2);
	_beam_spill_end                 = p.get<double>("BeamSpillEnd",   4.8);

	_debug                          = p.get<bool>("Debug", false);
	_verbose                        = p.get<bool>("Verbose", false);

	_cosmic_only                    = p.get<bool>("CosmicOnly", false);
	_use_premade_ass                = p.get<bool>("UsePremadeAssociation", true);
	_mcpHitAssLabel                 = p.get<std::string>("MCPHitAssProducer", "pandoraCosmicHitRemoval");


	if(_verbose) {std::cout << "[TpcObjectMaker] --- fcl parameters set --- " << std::endl; }

	produces< std::vector<xsecAna::TPCObject> >();
	produces< art::Assns<xsecAna::TPCObject,   recob::Track> >();
	produces< art::Assns<xsecAna::TPCObject,   recob::Shower> >();
	produces< art::Assns<xsecAna::TPCObject,   recob::PFParticle> >();


}

void xsecAna::TpcObjectMaker::produce(art::Event & e)
{
	// Implementation of required member function here.
	art::ServiceHandle<cheat::BackTracker> bt;
	nue_xsec::recotruehelper _recotruehelper_instance;
	xsecAna::tpcobjecthelper _tpcobjecthelper_instance;

	run = e.id().run();
	event = e.id().event();
	bool _is_data = e.isRealData();
	bool _is_mc = !_is_data;
	if(!_use_premade_ass)
	{
		if(_is_mc && !_cosmic_only) {_recotruehelper_instance.Configure(e, _pfp_producer, _spacepointLabel, _hitfinderLabel, _geantModuleLabel); }
	}
	if(_use_premade_ass)
	{
		if(_is_mc && !_cosmic_only) {_recotruehelper_instance.Configure(e, _pfp_producer, _spacepointLabel, _hitfinderLabel, _geantModuleLabel,
			                                                        _mcpHitAssLabel, lar_pandora::LArPandoraHelper::kAddDaughters); }
	}
	if(_verbose && _is_mc)  {std::cout << "[TpcObjectMaker] --- Running with MC --- " << std::endl; }
	if(_verbose && _is_data) {std::cout << "[TpcObjectMaker] --- Running with Data --- "<< std::endl; }

// Instantiate the output
	std::unique_ptr< std::vector< xsecAna::TPCObject > >                 tpcObjectVector        (new std::vector<xsecAna::TPCObject>);
	std::unique_ptr< art::Assns<xsecAna::TPCObject, recob::Track> >      assnOutTPCObjectTrack  (new art::Assns<xsecAna::TPCObject, recob::Track>      );
	std::unique_ptr< art::Assns<xsecAna::TPCObject, recob::Shower> >     assnOutTPCObjectShower (new art::Assns<xsecAna::TPCObject, recob::Shower>     );
	std::unique_ptr< art::Assns<xsecAna::TPCObject, recob::PFParticle> > assnOutTPCObjectPFP    (new art::Assns<xsecAna::TPCObject, recob::PFParticle> );


// Use LArPandoraHelper functions to collect Pandora information
	lar_pandora::PFParticleVector pfParticleList;        //vector of PFParticles
	lar_pandora::LArPandoraHelper::CollectPFParticles(e, _pfp_producer, pfParticleList);

// Collect vertices, tracks and shower
	lar_pandora::VertexVector allPfParticleVertices;
	lar_pandora::PFParticlesToVertices pfParticleToVertexMap;
	lar_pandora::LArPandoraHelper::CollectVertices(e, _vertexLabel, allPfParticleVertices, pfParticleToVertexMap);
	lar_pandora::TrackVector allPfParticleTracks;
	lar_pandora::PFParticlesToTracks pfParticleToTrackMap;
	lar_pandora::LArPandoraHelper::CollectTracks(e, _trackLabel, allPfParticleTracks, pfParticleToTrackMap);
	lar_pandora::ShowerVector allPfParticleShowers;
	lar_pandora::PFParticlesToShowers pfParticleToShowerMap;
	lar_pandora::LArPandoraHelper::CollectShowers(e, _showerLabel, allPfParticleShowers, pfParticleToShowerMap);


	std::vector<lar_pandora::TrackVector     > track_v_v;
	std::vector<lar_pandora::ShowerVector    > shower_v_v;
	std::vector<lar_pandora::PFParticleVector> pfp_v_v;
	std::vector<int> p_v, t_v, s_v;

	_tpcobjecthelper_instance.tpcobjecthelper::GetTPCObjects(pfParticleList, pfParticleToTrackMap, pfParticleToShowerMap,
	                                                         pfParticleToVertexMap, pfp_v_v, track_v_v, shower_v_v, p_v, t_v, s_v);

	lar_pandora::MCParticlesToPFParticles matchedParticles;    // This is a map: MCParticle to matched PFParticle
	lar_pandora::MCParticlesToHits matchedParticleHits;
	if (_is_mc)
	{
		_recotruehelper_instance.GetRecoToTrueMatches(matchedParticles, matchedParticleHits);
	}

//reco true matching is performed here!
	std::vector<art::Ptr<recob::PFParticle> > neutrinoOriginPFP;
	std::vector<art::Ptr<recob::PFParticle> > cosmicOriginPFP;

	if(!neutrinoOriginPFP.empty()) {neutrinoOriginPFP.clear(); }
	if(!cosmicOriginPFP.empty()) {cosmicOriginPFP.clear(); }

	std::vector< std::pair< int, simb::Origin_t > > pfp_origin_v;
	if(!pfp_origin_v.empty()) {pfp_origin_v.clear(); }

	//only perform matching if we have beam and is mc
	if(_cosmic_only == false && _is_mc == true)
	{
		for (lar_pandora::MCParticlesToPFParticles::const_iterator iter1 = matchedParticles.begin(), iterEnd1 = matchedParticles.end();
		     iter1 != iterEnd1; ++iter1)
		{
			art::Ptr<simb::MCParticle>  mc_par = iter1->first;// The MCParticle
			art::Ptr<recob::PFParticle> pf_par = iter1->second; // The matched PFParticle

			const art::Ptr<simb::MCTruth> mc_truth = bt->TrackIDToMCTruth(mc_par->TrackId());

			if (!mc_truth) {
				std::cerr << "[TPCObjectMaker] Problem with MCTruth pointer." << std::endl;
				continue;
			}
			std::pair < int, simb::Origin_t > pfp_origin (pf_par->Self(), mc_truth->Origin());
			pfp_origin_v.emplace_back(pfp_origin);
		} //end looping mc to pfp
	}

//loop over TPC objects
	for (size_t pfparticle_vector = 0; pfparticle_vector < pfp_v_v.size(); pfparticle_vector++)
	{

		xsecAna::TPCObject obj;

		// Set tracks
		std::vector<art::Ptr<recob::Track> > trk_v;
		for (auto t : track_v_v[pfparticle_vector]) trk_v.emplace_back(t);
		obj.SetTracks(trk_v);

		// Set showers
		std::vector<art::Ptr<recob::Shower> > shwr_v;
		for (auto s : shower_v_v[pfparticle_vector]) shwr_v.emplace_back(s);
		obj.SetShowers(shwr_v);

		//set individual particle origins
		std::vector<simb::Origin_t> origin_v;
		// Set PFPs
		std::vector<recob::PFParticle> pfp_v;
		//pfp_v.clear();
		for (auto p : pfp_v_v[pfparticle_vector])
		{
			pfp_v.emplace_back((*p));
			const int pfp_id = p->Self();
			simb::Origin_t pfp_origin = simb::kUnknown; //this is for the case where the pfp is not matched
			bool matched = false;
			for(auto const pp : pfp_origin_v)
			{
				if(pfp_id == pp.first)
				{
					matched = true;
					origin_v.emplace_back(pp.second);
				}
			}
			if(matched == false) {origin_v.emplace_back(pfp_origin); }
		}
		obj.SetPFPs(pfp_v);
		obj.SetParticleOrigins(origin_v);

		// Set vertex
		art::Ptr<recob::PFParticle> pfp = _tpcobjecthelper_instance.tpcobjecthelper::GetNuPFP(pfp_v_v[pfparticle_vector]);
		auto iter = pfParticleToVertexMap.find(pfp);
		if (iter != pfParticleToVertexMap.end()) {obj.SetVertex(*(iter->second[0])); }

		// Set origin
		simb::Origin_t origin = simb::kUnknown;
		if (_is_mc)
		{
			origin = _tpcobjecthelper_instance.tpcobjecthelper::GetSliceOrigin(neutrinoOriginPFP, cosmicOriginPFP, pfp_v_v[pfparticle_vector]);
		}
		obj.SetOrigin(origin);

		// Set Multiplicity
		obj.SetMultiplicity(p_v[pfparticle_vector], t_v[pfparticle_vector], s_v[pfparticle_vector]);

		tpcObjectVector->emplace_back(obj);
		util::CreateAssn(*this, e, *tpcObjectVector, track_v_v[pfparticle_vector],  *assnOutTPCObjectTrack);
		util::CreateAssn(*this, e, *tpcObjectVector, shower_v_v[pfparticle_vector], *assnOutTPCObjectShower);
		util::CreateAssn(*this, e, *tpcObjectVector, pfp_v_v[pfparticle_vector],    *assnOutTPCObjectPFP);

	} // end looping pfparticle_vectors (tpc objects)

// Put TPCObjects into the Event
	e.put(std::move(tpcObjectVector));
	e.put(std::move(assnOutTPCObjectTrack));
	e.put(std::move(assnOutTPCObjectShower));
	e.put(std::move(assnOutTPCObjectPFP));

	if (_debug) std::cout << "[TPCObjectMaker] Ends" << std::endl;
}

DEFINE_ART_MODULE(xsecAna::TpcObjectMaker)
