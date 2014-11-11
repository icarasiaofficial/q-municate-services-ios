//
//  NSEntityDescription+QMCDDataImport.h
//  QMCD Record
//
//  Created by Saul Mora on 9/5/11.
//  Copyright 2011 QMCD Panda Software LLC. All rights reserved.
//

/**
 Category methods on NSEntityDescription used in QMCDRecord's data import process.

 @since Available in v1.8 and later.
 */
@interface NSEntityDescription (QMCDRecordDataImport)

///-------------------------------
/// @name Managed Object Creation
///-------------------------------

/**
 Creates and returns a new NSManagedObject in the supplied NSManagedObject Context using the current entity description.

 @param context Managed Object Context
 @return Newly inserted managed object
 */
- (NSManagedObject *)QM_createInstanceInContext:(NSManagedObjectContext *)context;

///---------------------------------------
/// @name Attribute Description Retrieval
///---------------------------------------

/**
 Safely returns an attribute description for the given name, otherwise returns nil.

 In certain circumstances, the keys of the dictionary returned by `attributesByName` are not standard NSStrings and won't match using object subscripting or standard `objectForKey:` lookups.

 There may be performance implications when using this method if your entity has a large number of attributes (greater than 100).

 @param name Name of the attribute description in the `attributesByName` dictionary on this instance
 @return The attribute description for the given name, or nil if it could not be found
 */
- (NSAttributeDescription *)QM_attributeDescriptionForName:(NSString *)name;

/**
 @abstract Safely returns an attribute description for the value of the "relatedByAttribute" set in the data model on this entity.
 @return The attribute description for the provided "relatedByAttribute", or nil if it could not be found
 */
- (NSAttributeDescription *)QM_primaryAttributeToRelateBy;

- (NSAttributeDescription *) QM_primaryAttribute;

@end
