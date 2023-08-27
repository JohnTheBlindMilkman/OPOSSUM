#ifndef TrackCandidate_h
    #define TrackCandidate_h

    class TrackCandidate
    {
        public:
            TrackCandidate();
            virtual ~TrackCandidate() = default;

        private:
            int fPid, fMotherPid;
            float fMomX, fMomY, fMomZ, fEne, fPosX, fPosY, fPosZ, fRap, fMomT, fBeta, fMass;
    };

#endif