Pod::Spec.new do |s|

  s.name         = "ROHBuilder"
  s.version      = "0.1.0"
  s.summary      = "A new awesome paradigm for creating and configuring objects in Objective-C."

  s.description  = <<-DESC
                   Finally you can type new object initialization and configuration code faster than you can even think it through. Wow.
                   DESC

  s.homepage     = "https://github.com/repomies/ROHBuilder"

  s.license      = "Poropietari"

  s.author             = { "Janne Käki" => "janne@awesomeness.pro" }
  s.social_media_url   = "http://twitter.com/ronsu"

  s.platform     = :ios
  s.platform     = :ios, "7.0"

  s.source       = { :git => "https://github.com/repomies/ROHBuilder.git", :tag => "0.1.0" }
  s.source_files  = "*.{h,m}"

  s.requires_arc = true

end
