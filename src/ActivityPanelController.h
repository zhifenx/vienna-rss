//
//  ActivityPanelController.h
//  Vienna
//
//  Created by Steve on Thu Mar 18 2004.
//  Copyright (c) 2004-2005 Steve Palmer. All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

@import Cocoa;

@class Folder;

@protocol ActivityPanelDelegate

/**
 Notifies the delegate that a folder has been selected.

 @param activityPanel The panel in which the folder was selected.
 @param folder The selected folder.
 */
- (void)activityPanel:(nonnull NSPanel *)activityPanel didSelectFolder:(nonnull Folder *)folder;

@end

@interface ActivityPanelController : NSWindowController

/**
 The activity panel's delegate.
 */
@property (nullable, nonatomic) id<ActivityPanelDelegate> activityPanelDelegate;

@end
