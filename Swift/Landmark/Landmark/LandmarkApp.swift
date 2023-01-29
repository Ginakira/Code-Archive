//
//  LandmarkApp.swift
//  Landmark
//
//  Created by Sakata on 2023/1/26.
//

import SwiftUI

@main
struct LandmarkApp: App {
    @StateObject var modelData = ModelData()
    
    var body: some Scene {
        WindowGroup {
            ContentView()
                .environmentObject(modelData)
        }
    }
}
