/*
 *    Copyright (c) 2020 Google LLC.
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *    @file
 *      A trait data sink implementation for the OCSensor Weave Security SecurityOpenCloseTrait.
 */

#ifndef OCSENSOR_SECURITY_OPEN_CLOSE_TRAIT_DATA_SINK_H
#define OCSENSOR_SECURITY_OPEN_CLOSE_TRAIT_DATA_SINK_H

#include <Weave/Profiles/data-management/DataManagement.h>
#include <Weave/Profiles/data-management/TraitData.h>

class OCSensorSecurityOpenCloseTraitDataSink : public nl::Weave::Profiles::DataManagement::TraitDataSink
{
public:
    OCSensorSecurityOpenCloseTraitDataSink();
    bool IsOpen();

private:
    WEAVE_ERROR SetLeafData(nl::Weave::Profiles::DataManagement::PropertyPathHandle aLeafHandle,
                            nl::Weave::TLV::TLVReader & aReader);

    int32_t mSecurityOpenCloseState;
};

#endif /* OCSENSOR_SECURITY_OPEN_CLOSE_TRAIT_DATA_SINK_H */
