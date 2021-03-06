/**
 * \class ubana::TPCObject
 *
 * \ingroup UBXSec
 *
 * \brief Data product to store a TPC Object
 *
 *
 * \author $Author: Marco Del Tutto<marco.deltutto@physics.ox.ac.uk> $
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2017/03/02 $
 *
 * Contact: marco.deltutto@physics.ox.ac.uk
 *
 * Created on: Friday, May 15, 2017 at 16:34:34
 *
 */

#ifndef TPCObject_h
#define TPCObject_h

//#include "AnaHelper.h"

#include "canvas/Persistency/Common/Ptr.h"

#include "lardataobj/RecoBase/Track.h"
#include "lardataobj/RecoBase/Shower.h"
#include "lardataobj/RecoBase/PFParticle.h"
#include "lardataobj/RecoBase/Vertex.h"
#include "nusimdata/SimulationBase/MCTruth.h"


#include <vector>

namespace xsecAna {

enum TPCObjectOrigin {
	kUnknown = -1,      // -1
	kBeamNeutrino = 0,  // 0
	kCosmicRay,         // 1
	kMixed,             // 2
};

enum TPCObjectOriginExtra {
	kNotSet = -1,       // -1
	kStoppingMuon = 0,  // 0
	kACPT,              // 1
	kNCPion,            // 2
	kNCProton,          // 3
};
}


namespace xsecAna {

class TPCObject {

public:

TPCObject();
//virtual ~TPCObject();

// Setter methods
void SetTracks(std::vector <art::Ptr<recob::Track>  >);
void SetShowers(std::vector<art::Ptr<recob::Shower> >);
void SetPFPs(std::vector<recob::PFParticle>);
void SetVertex(recob::Vertex);
void SetOrigin(simb::Origin_t);
void SetOriginExtra(simb::Origin_t);
void SetParticleOrigins (std::vector< simb::Origin_t > origins);
void SetMultiplicity(int pfpMult, int trackMult, int showerMult);

// Getter methods
const std::vector<art::Ptr<recob::Track> >               & GetTracks()          const;
const std::vector<art::Ptr<recob::Shower> >              & GetShowers()         const;
const std::vector<recob::PFParticle>          & GetPFPs()            const;
const recob::Vertex                           & GetVertex()          const;
const simb::Origin_t                          & GetOrigin()          const;
const simb::Origin_t                          & GetOriginExtra()     const;
const std::vector<simb::Origin_t>             & GetParticleOrigins() const;
const size_t                                  GetNTracks()           const;
const size_t                                  GetNShowers()          const;
const size_t                                  GetNPFP()              const;
const void                                    GetMultiplicity(int &, int &, int &) const;
const int                                     GetNTracksCloseToVertex(double)      const;

private:

std::vector<art::Ptr<recob::Track>  >     fTracks;
std::vector<art::Ptr<recob::Shower> >     fShowers;
std::vector<recob::PFParticle> fPFParticles;
recob::Vertex fVertex;
std::vector< simb::Origin_t > fOriginVector;
simb::Origin_t fOrigin;
simb::Origin_t fOriginExtra;
int fPfpMult;
int fTrackMult;
int fShowerMult;
};
} //end namespace

#endif /* TPCObject_h */
