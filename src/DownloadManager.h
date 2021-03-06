//
//  DownloadManager.h
//  Vienna
//
//  Created by Steve on 10/7/05.
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

#import <Cocoa/Cocoa.h>
#import <WebKit/WebKit.h>

typedef NS_ENUM(NSInteger, DownloadState) {
    DownloadStateInit,
    DownloadStateStarted,
    DownloadStateCompleted,
    DownloadStateFailed,
    DownloadStateCancelled
};

@interface DownloadItem : NSObject<NSCoding> {
	long long expectedSize;
	long long fileSize;
	DownloadState state;
	NSImage * image;
	NSString * filename;
	NSURLDownload * download;
	NSDate * startTime;
}

// Public functions
@property (nonatomic) DownloadState state;
@property (nonatomic) long long expectedSize;
@property (nonatomic) long long size;
@property (nonatomic, strong) NSURLDownload *download;
@property (nonatomic, copy) NSString *filename;
@property (nonatomic, readonly, copy) NSImage *image;
@property (nonatomic, copy) NSDate *startTime;
@end

@interface DownloadManager : NSObject <WebDownloadDelegate> {
	NSMutableArray * downloadsList;
	NSInteger activeDownloads;
}

// Public functions
+(DownloadManager *)sharedInstance;
+(BOOL)isFileDownloaded:(NSString *)filename;
+(NSString *)fullDownloadPath:(NSString *)filename;
@property (nonatomic, readonly, copy) NSArray *downloadsList;
@property (nonatomic, readonly) NSInteger activeDownloads;
-(void)clearList;
-(void)cancelItem:(DownloadItem *)item;
-(void)removeItem:(DownloadItem *)item;
-(void)downloadFileFromURL:(NSString *)url;
@end
