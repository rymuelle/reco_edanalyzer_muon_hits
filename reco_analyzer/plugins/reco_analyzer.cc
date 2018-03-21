// -*- C++ -*-
//
// Package:    reco_analyzer/reco_analyzer
// Class:      reco_analyzer
// 
/**\class reco_analyzer reco_analyzer.cc reco_analyzer/reco_analyzer/plugins/reco_analyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Ryan Dalrymple Mueller
//         Created:  Wed, 21 Mar 2018 15:53:13 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.

class reco_analyzer : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit reco_analyzer(const edm::ParameterSet&);
      ~reco_analyzer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

      edm::EDGetTokenT<reco::TrackCollection>                    generalTracksToken                     ;

      // ----------member data ---------------------------
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
reco_analyzer::reco_analyzer(const edm::ParameterSet& iConfig):
generalTracksToken(consumes<reco::TrackCollection>(iConfig.getParameter<edm::InputTag>("generalTracks")))
{
   //now do what ever initialization is needed
   usesResource("TFileService");

}


reco_analyzer::~reco_analyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
reco_analyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;

  /* Handle<reco::TrackCollection> tracks;
   //Handle<std::vector<reco::Track>> tracks;
   iEvent.getByLabel("generalTracks", tracks); 
   LogInfo("Demo") << "number of tracks "<< tracks->size();*/

   //EDGetTokenT<reco::TrackCollection>   track_token;
   //track_token(consumes<reco::TrackCollection>(edm::InputTag("generalTracks", "", "RECO")));
   //track_token(consumes<reco::TrackCollection>("generalTracks"));
   Handle<reco::TrackCollection> tracks;
   iEvent.getByToken(generalTracksToken, tracks);



#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void 
reco_analyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
reco_analyzer::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
reco_analyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(reco_analyzer);
