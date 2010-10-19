// Protocol Buffers for Objective C
//
// Copyright 2010 Booyah Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#import <Foundation/Foundation.h>

#import "PBGenericDescriptor.h"

@class PBDescriptor;
@class PBEnumDescriptorProto;
@class PBEnumOptions;
@class PBEnumValueDescriptor;
@class PBEnumValueDescriptorProto;
@class PBEnumValueOptions;
@class PBFileDescriptor;

@interface PBEnumDescriptor : NSObject <PBGenericDescriptor>
{
@private
	NSInteger					_index;
	PBEnumDescriptorProto *		_proto;
	NSString *					_fullName;
	PBFileDescriptor *			_file;
	PBDescriptor *				_containingType;
	NSMutableArray *			_values;
}

@property (nonatomic,assign,readonly) NSInteger				index;
@property (nonatomic,retain,readonly) PBGeneratedMessage *	proto;
@property (nonatomic,retain,readonly) NSString *			name;
@property (nonatomic,retain,readonly) NSString *			fullName;
@property (nonatomic,retain,readonly) PBFileDescriptor *	file;
@property (nonatomic,retain,readonly) PBDescriptor *		containingType;
@property (nonatomic,retain,readonly) NSArray *				values;
@property (nonatomic,retain,readonly) PBEnumOptions *		options;

- (PBEnumValueDescriptor *)valueNamed:(NSString *)name;
- (PBEnumValueDescriptor *)valueNumbered:(NSInteger)number;

@end

// Describes one value within an enum type.
@interface PBEnumValueDescriptor : NSObject <PBGenericDescriptor>
{
@private
	NSInteger						_index;
	PBEnumValueDescriptorProto *	_proto;
	NSString *						_fullName;
	PBFileDescriptor *				_file;
	PBEnumDescriptor *				_type;
}

@property (nonatomic,assign,readonly) NSInteger				index;
@property (nonatomic,retain,readonly) PBGeneratedMessage *	proto;
@property (nonatomic,retain,readonly) NSString *			name;
@property (nonatomic,assign,readonly) NSInteger				number;
@property (nonatomic,retain,readonly) NSString *			fullName;
@property (nonatomic,retain,readonly) PBFileDescriptor *	file;
@property (nonatomic,retain,readonly) PBEnumDescriptor *	type;
@property (nonatomic,retain,readonly) PBEnumValueOptions *	options;

@end